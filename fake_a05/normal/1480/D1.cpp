#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
//#define endl '\n'


//#define int long long
const int maxN = 5e5 + 5;
int cnt(vi &x)
{
	int re = 0;
	loop(i, 0, (int) x.size() - 1)
	{
		if(i + 1 == x.size() or x[i] != x[i + 1]) re++; 
	}
	return re;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int N; 
	cin >> N; 
	vi x, a, b;
	loop(i, 1, N)
	{
		int t;
		cin >> t;
		if(x.size() < 2 or x.back() != t or x[(int) x.size() - 2] != t) x.eb(t);
	}
	for(int t: x)
	{
		if(!a.empty() and t == a.back())
		{
			if(!b.empty() and b.back() != a.back()) 
			{
				a.eb(b.back());
				b.pop_back();
			}
		}
		if(b.empty() or t != b.back()) b.eb(t);
		else a.eb(t);
	} 
	cout << cnt(a) + cnt(b);
}