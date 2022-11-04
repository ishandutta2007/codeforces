#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 2e5 + 20;
const ll mod[2] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const ll base[2] = {1000 * 200 + 7 , 1000 * 1000 + 3};

int a[maxn] , b[maxn] , c[maxn];

set<pair<int , int> > st;

ll pw[maxn][2] , h_a[2] , fen[maxn][2];

void add(int p , ll val)
{
	int tmp = p + 1;
	for(int j = 0; j < 2; j++)
		for(p++; p < maxn; p += lb(p))
			fen[p][j] = (fen[p][j] + (val * pw[p - tmp][j] % mod[j]) + mod[j]) % mod[j];
}

ll get(int p , int j)
{
	ll res = 0;
	int tmp = p + 1;
	for(p++; p > 0; p -= lb(p))
		res = (res + fen[p][j] * pw[tmp - p][j]) % mod[j];
	return res;
}

void change(int pos , int val)
{
	add(pos , -c[pos] + val);
	c[pos] = val;
}

void rem(int x , int pos)
{
	pair<int , int> tmp = {x , pos};

	auto it = st.find(tmp);

	change(pos , 0);

	if(it != st.begin())
	{
		it--;
		int z = it -> second;
		it++ , it++;

		if(it == st.end())
			change(z , 0);
		else
			change(z , (it -> second) - z);
	}
	st.erase(tmp);
}

void add(int x , int pos)
{
	pair<int , int> tmp = {x , pos};
	st.insert(tmp);

	auto it = st.find(tmp);
	it++;
	if(it != st.end())
		change(pos , (it -> second) - pos);
	else
		change(pos , 0);
	it--;

	if(it != st.begin())
	{
		it--;
		change(it -> second , pos - (it -> second));
	}
}

void prepare()
{
	pw[0][0] = pw[0][1] = 1;

	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < 2; j++)
			pw[i][j] = pw[i - 1][j] * base[j] % mod[j];
}

int main()
{
	prepare();

	int n , m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		a[x] = i;
	}
	for(int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		b[x] = i;
	}

	for(int i = 0; i < n; i++)
		add(a[i] , i);

	for(int j = 0; j < 2; j++)
		h_a[j] = get(n - 1 , j);

	for(int i = 0; i < n; i++)
		rem(a[i] , i);

	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		add(b[i] , i);
		if(i + 1 > n)
			rem(b[i - n] , i - n);
		else if(i + 1 != n)
			continue;

		bool f = 1;
		for(int j = 0; j < 2; j++)
		{
			ll res = get(i , j) - (get(i - n , j) * pw[n][j] % mod[j]) + mod[j];
			res %= mod[j];
			f &= (res == h_a[j]);
		}
		ans += f;
	}
	cout << ans << endl;
}