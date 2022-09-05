//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
bitset<524288> a;
int n,k,p[1000111],cnt[1000111];
bool vis[1000111];
int main()
{
	geti(n);geti(k);
	int ok=k;
	for(int i=1;i<=n;i++)geti(p[i]);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		int x=i,len=0;
		if(vis[x])continue;
		while(!vis[x])
		{
			vis[x]=1;
			len++;
			x=p[x];
		}
		cnt[len]++;
		tot+=len/2;
	}
	for(int i=1;i<=500000;i++)
	{
		if(!cnt[i])continue;
		cnt[i<<1]+=(cnt[i]-1)>>1;
		cnt[i]=(cnt[i]-1)%2+1;
	}
	int mxans=min(n,max(0,k-tot)+min(k,tot)*2);
	k=min(k,n-k);
	a[0]=1;
	for(int i=1;i<=500000;i++)
	{
		while(cnt[i]--)
		{
			a|=a<<i;
		}
	}
	cout<<ok+1-a[k]<<" "<<mxans<<endl;
	return 0;
}