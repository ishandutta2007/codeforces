#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int maxx = 2e5;
const int maxl = 5e5;
const int MAXL = maxl + 5;

inline int read(void)
{
	int res=0; char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

int a[MAXN];
int ans[MAXL];

int main(void)
{
	int n=read(), x=read(), y=read();
	for(int i=0; i<=n; ++i) a[i] = read();
	
	bitset<maxx+1> b, aa;
	for(int i=0; i<=n; ++i)
		aa.set(a[i]);
	for(int i=0; i<n; ++i)
		b |= (aa>>a[i]);
	
	memset(ans,-1,sizeof(ans));
	for(int i=y+1; i-y<=x; ++i) if(b[i-y])
		for(int j=i; j<=maxl; j+=i)
			ans[j] = i<<1;
	
	int Q = read();
	while(Q--)
	{
		int l = read();
		printf("%d ",ans[l>>1]);
	}
	return 0;
}