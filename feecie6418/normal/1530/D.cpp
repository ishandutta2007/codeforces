#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005],vst[200005],fr[200005],to[200005],st[200005],top,low[200005],dfn[200005],ins[200005],sign,cnt[200005];
int ind[200005],SCC,bel[200005];
void Tarjan(int x){
	st[++top]=x,ins[x]=1,dfn[x]=low[x]=++sign;
	int y=a[x];
	if(!dfn[y])Tarjan(y),low[x]=min(low[x],low[y]);
	else if(ins[y])low[x]=min(low[x],dfn[y]);
	if(low[x]==dfn[x]){
		int tmp=0;
		SCC++;
		while(tmp!=x)bel[tmp=st[top--]]=SCC,cnt[SCC]++,ins[tmp]=0;
	}
}
int main(){
	//freopen("1.in","r",stdin);
	int t,cntt=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
		for(int i=1;i<=n;i++)vst[a[i]]++;
		for(int i=1;i<=n;i++){
			if(vst[a[i]]==1)b[i]=a[i];
			else if(cnt[bel[i]]==1&&vst[a[i]])b[i]=a[i],vst[a[i]]=0;
		}
		for(int i=1;i<=n;i++)if(b[i])ind[b[i]]++;
		//cout<<fr[0]<<endl;
		for(int i=1;i<=n;i++){
			if(!ind[i]){
				fr[++fr[0]]=i;
				int u=i;
				while(b[u])u=b[u];
				to[++to[0]]=u;
			}
		}
		//cout<<fr[0]<<endl;
		for(int i=1;i<=fr[0];i++)b[to[i]]=fr[i%fr[0]+1];
		//for(int i=1;i<=fr[0];i++)cout<<fr[i]<<' '<<to[i]<<' '<<b[to[i]]<<'\n';
		int ans=0;
		for(int i=1;i<=n;i++)ans+=(a[i]==b[i]);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)cout<<b[i]<<' ',assert(i!=b[i]);
		puts("");
		cerr<<(++cntt)<<'\n';
		for(int i=1;i<=n;i++)a[i]=b[i]=vst[i]=fr[i]=to[i]=st[i]=low[i]=dfn[i]=ins[i]=cnt[i]=ind[i]=bel[i]=0;
		top=sign=SCC=fr[0]=to[0]=0;
	}
}