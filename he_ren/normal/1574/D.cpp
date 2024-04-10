#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 10 + 5;
const int MAXM = 1e5 + 5;
const int mod = 1e9 + 7;
int base;

int n;
vector<int> a[MAXN], fob[MAXM];

inline int get_hash(const vector<int> &vec)
{
	int res = 0;
	for(int i=1; i<=n; ++i)
		res = ((ll)res * base + vec[i]) %mod;
	return res;
}

inline void get_val(vector<int> &vec)
{
	int res = 0;
	for(int i=1; i<=n; ++i)
		res += a[i][vec[i] - 1];
	vec[0] = -res;
}

unordered_set<int> ids;

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	base = rand() + 1919810;
	
	scanf("%d",&n);
	vector<int> beg(n+1);
	for(int i=1; i<=n; ++i)
	{
		int k;
		scanf("%d",&k);
		a[i].resize(k);
		for(int &x: a[i]) scanf("%d",&x);
		beg[i] = k;
	}
	get_val(beg);
	
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		fob[i].resize(n+1);
		for(int j=1; j<=n; ++j)
			scanf("%d",&fob[i][j]);
		get_val(fob[i]);
		ids.insert(get_hash(fob[i]));
	}
	
	set< vector<int> > q;
	q.emplace(beg);
	while(q.size())
	{
		vector<int> vec = *q.begin();
		q.erase(q.begin());
		if(ids.find(get_hash(vec)) == ids.end())
		{
			for(int i=1; i<=n; ++i)
				printf("%d ",vec[i]);
			return 0;
		}
		
		for(int i=1; i<=n; ++i) if(vec[i] > 1)
		{
			--vec[i];
			get_val(vec);
			q.emplace(vec);
			++vec[i];
		}
	}
	return 0;
}