#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

//#define He_Ren

#ifdef He_Ren

struct Jury
{
	int n,x, cnt;
	bool del[MAXN];
	Jury(void){ cnt=0; memset(del,0,sizeof(del));}
	
	int ask(char c,int k)
	{
		++cnt;
		
		if(c == 'C')
		{
			if(x == k) printf("Accepted! using %d queries\n",cnt);
			else printf("Wrong Answer!\n");
			exit(0);
		}
		if(c == 'B' && k == 1){ printf("Error! ask\"B 1\"!\n"); exit(0);}
		
		int res = 0;
		for(int i=k; i<=n; i+=k)
			if(!del[i])
			{
				++res;
				if(c == 'B' && i != x) del[i] = 1;
			}
		return res;
	}
}jury;

int ask(char c,int x){ return jury.ask(c,x);}
void answer(int x){ jury.ask('C',x);}

#endif

bool isnp[MAXN];
int p[MAXN], pcnt = 0;
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) p[++pcnt] = i;
		for(int j=1; j<=pcnt && (ll)i * p[j] <= n; ++j)
		{
			isnp[i*p[j]] = 1;
			if(!(i%p[j])) break;
		}
	}
}

#ifndef He_Ren

inline int ask(char c,int x)
{
	printf("%c %d\n",c,x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

inline void answer(int x){ printf("C %d\n",x); fflush(stdout); exit(0);}

#endif

int main(void)
{
#ifdef He_Ren
	int n,xx;
	scanf("%d%d",&n,&xx);
	jury.n = n; jury.x = xx;
#else
	int n;
	scanf("%d",&n);
#endif
	
	sieve(n);
	
	ll x = 1;
	int rem = 0;
	for(int i=1; i<=pcnt; ++i)
	{
		if((ll)p[i] * p[i] <= n)
		{
			ask('B',p[i]);
			
			int l=0, r=0;
			ll cur = 1;
			while(cur * x <= n)
				++r,
				cur *= p[i];
			--r;
			
			static int pw[100];
			pw[0] = 1;
			for(int j=1; j<=r; ++j) pw[j] = pw[j-1] * p[i];
			
			static int f[100];
			for(int j=0; j<=r; ++j) f[j] = -1;
			f[0] = 1;
			
			while(l<r)
			{
				int mid = (l+r+1)>>1;
				if(f[mid] == -1) f[mid] = ask('A',pw[mid]);
				
				if(f[mid]) l=mid;
				else r=mid-1;
			}
			
			x *= pw[l];
		}
		else ++rem;
	}
	
	int lst = ask('A',1);
	
	vector<int> q;
	for(int i=1; i<=pcnt && (ll)x * p[i] <= n; ++i) if((ll)p[i] * p[i] > n)
	{
		int res = ask('B', p[i]);
		if(res > 1) answer(x * p[i]);
		
		q.push_back(p[i]);
		if((int)q.size() >= 90)
		{
			int now = ask('A',1);
			if(lst - now != (int)q.size())
			{
				for(int j=0; j<(int)q.size(); ++j)
					if(ask('A',q[j])) answer(x * q[j]);
			}
			rem -= (int)q.size();
			q.clear();
			lst = now;
		}
	}
	
	if(q.size())
	{
		ll now = ask('A',1);
		if(lst - now != (int)q.size())
		{
			for(int j=0; j<(int)q.size(); ++j)
				if(ask('A',q[j])) answer(x * q[j]);
		}
	}
	
	answer(x);
	return 0;
}