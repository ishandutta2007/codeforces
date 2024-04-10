#include<cstdio>
#include<cstring>
typedef long long ll;
const int MAXM = 2e3 + 5;
const int MAXN = 2e3 + 5;
const int mod = 1e9 + 7;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}
inline void add(ll &a,ll b){ a+=b; if(a>=mod) a-=mod;}

char a[MAXN],b[MAXN];
ll f[MAXM][4], g[MAXM][4];

int main(void)
{
	int m,d;
	scanf("%d%d%s%s",&m,&d,a,b);
	int n=strlen(a);
	
	for(int i=0; i<n; ++i)
		a[i]-='0', b[i]-='0';
	
	f[0][0]=1;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
			for(int k=0; k<4; ++k)
				g[j][k]=f[j][k], f[j][k]=0;
		
		for(int j=0; j<m; ++j)
			for(int k=0; k<4; ++k) if(g[j][k])
			{
				int
					frm = (k&1)? 0: a[i],
					to = (k>>1)? 9: b[i];
				if(i&1)
				{
					chk_max(frm,d);
					chk_min(to,d);
				}
				
				for(int x=frm; x<=to; ++x)
					if((i&1)==(x==d))
						add( f[(j*10+x)%m][ k | (x>a[i]) | ((x<b[i])<<1) ], g[j][k]);
			}
	}
	
	ll ans=0;
	for(int k=0; k<4; ++k) add(ans, f[0][k]);
	printf("%d",(int)ans);
	return 0;
}