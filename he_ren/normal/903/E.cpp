#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Mp make_pair
#define fir first
#define sec second
const int MAXM = 5e3 + 5;
const int MAXN = 5e3 + 5;
const int mod1 = 19260817;
const int mod2 = 19491001;

int pw1[MAXN],pw2[MAXN];

int m,n;
char s[MAXM][MAXN];
bool dif[MAXM][MAXN];
map<pii,int> t;

inline int dig1(char c,int pos){ return pw1[n-pos]*(c-'0') %mod1;}
inline int dig2(char c,int pos){ return pw2[n-pos]*(c-'0') %mod2;}

int main(void)
{
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; ++i)
		scanf("%s",s[i]+1);
	
	bool skp=1;
	for(int i=1; i<=m; ++i)
		for(int j=1; j<i; ++j)
		{
			int cnt=0;
			for(int k=1; k<=n; ++k)
				if(s[i][k] != s[j][k])
				{
					++cnt;
					dif[i][k]=dif[j][k]=1;
					skp=0;
				}
			if(cnt>4){ printf("-1"); return 0;}
		}
	if(skp)
	{
		swap(s[1][1],s[1][2]);
		printf("%s",s[1]+1);
		return 0;
	}
	
	pw1[0]=pw2[0]=1;
	for(int i=1; i<=n; ++i)
		pw1[i] = pw1[i-1]*10 %mod1,
		pw2[i] = pw2[i-1]*10 %mod2;
	
	for(int i=1; i<=m; ++i)
	{
		int h1=0, h2=0;
		for(int j=1; j<=n; ++j)
			h1 = (h1*10 + s[i][j]-'0') %mod1,
			h2 = (h2*10 + s[i][j]-'0') %mod2;
		
		bool flag=0;
		for(int j=1; j<=n; ++j)
		{
			int tmp1 = dig1(s[i][j],j), tmp2 = dig2(s[i][j],j);
			for(int k=1; k<j; ++k)
			{
				if(!dif[i][j] && !dif[i][k]) continue;
				if(s[i][j]==s[i][k])
				{
					if(flag) continue;
					flag=1;
				}
				
				int hsh1 = h1 -tmp1-dig1(s[i][k],k) +dig1(s[i][j],k)+dig1(s[i][k],j);
				int hsh2 = h2 -tmp2-dig2(s[i][k],k) +dig2(s[i][j],k)+dig2(s[i][k],j);
				
				hsh1%=mod1;
				if(hsh1<0) hsh1+=mod1;
				hsh2%=mod2;
				if(hsh2<0) hsh2+=mod2;
				
				int tot = ++t[ Mp(hsh1,hsh2) ];
				if(tot<i) t.erase( Mp(hsh1,hsh2) );
				if(tot==m)
				{
					swap(s[i][j], s[i][k]);
					printf("%s",s[i]+1);
					return 0;
				}
			}
		}	
	}
	printf("-1");
	return 0;
}