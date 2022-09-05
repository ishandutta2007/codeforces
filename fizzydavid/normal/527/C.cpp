//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int MAXN=200011;
int w,h,n,cnt[MAXN],p[MAXN],mx,b[MAXN];
bool op[MAXN],f[2][MAXN];
ll a[2][MAXN];
void init()
{
	for(int i=0;i<MAXN;i++)p[i]=i,cnt[i]=1;
	mx=1;
}
int gf(int x)
{
	if(p[x]==x)return x;
	return p[x]=gf(p[x]);
}
void un(int x,int y)
{
	int i=gf(x),j=gf(y);
	if(i!=j)
	{
		p[j]=i;
		cnt[i]+=cnt[j];
		mx=max(mx,cnt[i]);
	}
}
int main()
{
	scanf("%d%d%d",&w,&h,&n);
	char opc;
	for(int i=1;i<=n;i++)
	{
		getchar();
		scanf("%c %d",&opc,&b[i]);
		op[i]=(opc=='H');
		f[op[i]][b[i]]=1;
	}
	for(int k=0;k<2;k++)
	{
		init();
		for(int i=1;i<(k?h:w);i++)if(!f[k][i])un(i,i+1);
		for(int i=n;i>=1;i--)
		{
			a[k][i]=mx;
			if(op[i]==k)un(b[i],b[i]+1);
		}
	}
	for(int i=1;i<=n;i++)printf("%I64d\n",a[0][i]*a[1][i]);
	return 0;
}