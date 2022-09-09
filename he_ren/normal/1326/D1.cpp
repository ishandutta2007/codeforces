#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

char s[MAXN],tmp[MAXN],t[MAXN<<1];
int f[MAXN<<1];

void manacher(char s[],int &n)
{
	t[0]='$'; t[1]='#';
	for(int i=1; i<=n; ++i)
		t[i<<1]=s[i], t[i<<1|1]='#';
	n = n<<1|1;
	t[n+1]=0;
	
	int r=0,mid=0;
	for(int i=1; i<=n; ++i)
	{
		f[i]=0;
		if(i<r) f[i] = min(r-i, f[mid-(i-mid)]);
		while(t[i+f[i]]==t[i-f[i]]) ++f[i];
		if(i+f[i]>r) r=i+f[i], mid=i;
	}
}

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int pos = 1;
	while(pos<=(n>>1) && s[pos]==s[n-pos+1]) ++pos;
	--pos;
	
	int cnt=0;
	for(int i=pos+1; i<=n-pos; ++i)
		tmp[++cnt] = s[i];
	tmp[cnt+1]=0;
	
	int m=cnt;
	manacher(tmp,m);
	
	int mx=-1, ans;
	for(int i=1; i<=m; ++i)
		if(f[i]==i && mx<f[i])
		{
			mx = f[i];
			ans = i;
		}
	
	for(int i=1; i<=m; ++i)
		if(f[i]==m-i+1 && mx<f[i])
		{
			mx = f[i];
			ans = i;
		}
	
	for(int i=1; i<=pos; ++i) putchar(s[i]);
	if(mx>=0)
	{
		for(int i=ans-mx+1; i<ans+mx; ++i)
			if(t[i]!='#') putchar(t[i]);
	}
	for(int i=pos; i>=1; --i) putchar(s[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}