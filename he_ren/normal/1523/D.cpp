#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 60 + 5;
const int ALL = (1<<15) + 5;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

const int allN = (1<<20) - 1;
const int ALLN = allN + 5;
int num1[ALLN];
inline int get_num1(ll x){ return num1[(x >> 40) & allN] + num1[(x >> 20) & allN] + num1[x & allN];}

ll a[MAXN];

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	
	for(int i=1; i<ALLN; ++i) num1[i] = num1[i^lowbit(i)] + 1;
	
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1; i<=n; ++i)
	{
		static char s[MAXM];
		scanf("%s",s+1);
		for(int j=1; j<=m; ++j)
			if(s[j] == '1') a[i] |= bbit(j-1);
	}
	
	int need = (n + 1) >> 1, ans = 0;
	
	int T = min(n - need + 1, 30);
	
	vector<int> pos;
	for(int i=1; i<=n; ++i) pos.push_back(i);
	random_shuffle(pos.begin(), pos.end());
	pos.resize(T);
	
	ll ans_mask = 0;
	for(int k=0; k<(int)pos.size(); ++k)
	{
		vector<int> vec;
		for(int i=0; i<m; ++i)
			if(bdig(a[pos[k]], i))
				vec.push_back(i);
		
		int tot = (int)vec.size();
		int all = (1<<tot) - 1;
		if(tot <= ans) continue;
		
		static int f[ALL];
		memset(f, 0, (all+1)<<2);
		for(int i=1; i<=n; ++i)
		{
			int cur = 0;
			for(int j=0; j<tot; ++j)
				if(bdig(a[i], vec[j]))
					cur |= bbit(j);
			++f[cur];
		}
		
		for(int j=0; j<tot; ++j)
			for(int i=all; i>=1; --i)
				if(bdig(i, j))
					f[i ^ bbit(j)] += f[i];
		
		for(int i=all; i>=1; --i)
			if(num1[i] > ans && f[i] >= need)
			{
				ans = num1[i];
				ans_mask = 0;
				for(int j=0; j<tot; ++j)
					if(bdig(i, j)) ans_mask |= bbit(vec[j]);
			}
	}
	
	for(int i=0; i<m; ++i)
		putchar(bdig(ans_mask, i) + '0');
	return 0;
}