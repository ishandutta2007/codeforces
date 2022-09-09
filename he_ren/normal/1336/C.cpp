#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e3 + 5;
const int MAXM = 3e3 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int n,m;
char s[MAXN],t[MAXM];
int f[MAXM][MAXM];
int pw2[MAXN];

int gao(int pre,int suf)
{
	if(suf>m) return pw2[pre];
	if(pre<1) return 1;
	if(~f[pre][suf]) return f[pre][suf];
	int &res = f[pre][suf] = 0;
	
	if(suf+pre-1>m || t[suf+pre-1] == s[pre]) res = gao(pre-1,suf);
	if(t[suf] == s[pre]) add_mod(res, gao(pre-1,suf+1));
	return res;
}

int main(void)
{
	memset(f,-1,sizeof(f));
	
	pw2[0]=1;
	for(int i=1; i<MAXN; ++i) pw2[i] = (pw2[i-1]<<1) %mod;
	
	scanf("%s%s",s+1,t+1);
	n = strlen(s+1);
	m = strlen(t+1);
	
	int ans=0;
	for(int i=m; i<=n; ++i)
		add_mod(ans, gao(i,1));
	printf("%d",ans);
	return 0;
}