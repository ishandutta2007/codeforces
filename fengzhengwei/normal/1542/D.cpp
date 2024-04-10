#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=505;
int n,op[xx],val[xx],suf[xx],rnk[xx],id[xx];//1+ 2-
const int mod=998244353;
ll ans;
struct node
{
	int val,id;
	bool operator<(const node&w)const{return val==w.val?id<w.id:val<w.val;}
}e[xx];
ll f[xx][xx];
void c(ll &x,ll y){x+=y;if(x>=mod)x-=mod;}
int main(){
	n=read();
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		char c;while((c=getchar())!='+'&&c!='-');
		if(c=='+')op[i]=1,val[i]=e[++tot].val=read(),e[tot].id=tot,id[i]=tot;
		else op[i]=2;
	}
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++)rnk[e[i].id]=i;
	for(int i=1;i<=n;i++)
	{
		if(op[i]==2)continue;
		int now=rnk[id[i]];
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int j=0;j<i-1;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(!f[j][k])continue;
				if(op[j+1]==1&&rnk[id[j+1]]<now)c(f[j+1][k+1],f[j][k]);
				else if(op[j+1]==1&&rnk[id[j+1]]>now)c(f[j+1][k],f[j][k]);
				else if(op[j+1]==2)c(f[j+1][max(0,k-1)],f[j][k]);
				c(f[j+1][k],f[j][k]);
			}
		}
		for(int k=0;k<=n;k++)f[i][k]=f[i-1][k];
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(!f[j][k])continue;
				if(op[j+1]==1&&rnk[id[j+1]]<now)c(f[j+1][k+1],f[j][k]);
				else if(op[j+1]==1&&rnk[id[j+1]]>now)c(f[j+1][k],f[j][k]);
				else if(op[j+1]==2&&k!=0)c(f[j+1][k-1],f[j][k]);
				c(f[j+1][k],f[j][k]);
			}
		}
		for(int k=0;k<=n;k++)ans+=val[i]*f[n][k]%mod,ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}