#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
struct E{
	int x,y;
};
int n,m,K,bel[N],CNT,fa[N*2],size[N*2],sign,no[N],st[N*2][2],top;
ll ans;
vector<E> g[N];
map<ll,int> id;
int gf(int x){
	return x==fa[x]?x:gf(fa[x]);
}
void Merge(int x,int y){
	if((x=gf(x))==(y=gf(y)))return ;
//	cout<<x<<' '<<y<<endl;
	if(size[x]>size[y])swap(x,y);
	fa[x]=y,size[y]+=size[x],st[++top][0]=x,st[top][1]=y;
}
int main(){
	scanf("%d%d%d",&n,&m,&K),CNT=K;
	for(int i=1;i<=n;i++)scanf("%d",&bel[i]);
	for(int i=1;i<=2*n;i++)size[i]=1,fa[i]=i;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(bel[x]>bel[y])swap(x,y);
		ll o=1000000ll*bel[x]+bel[y];
		if(!id[o])id[o]=++sign;
		//cout<<o<<' '<<x<<' '<<y<<endl;
		g[id[o]].push_back({x,y});
	}
	for(int i=1;i<=K;i++){
		int p=id[1000000ll*i+i];
		if(!p)continue;
		for(E w:g[p]){
			int x=w.x,y=w.y;
			Merge(x+n,y),Merge(x,y+n);
			if(gf(x)==gf(y)){
				no[i]=1,CNT--;
				break;
			}
		}
	}
	ans=1ll*CNT*(CNT-1)/2;
	for(auto it:id){
		int x=(it.first-1)/1000000,y=(it.first-1)%1000000+1;
		if(no[x]||no[y]||x==y)continue;
		int tp=top;
		for(E w:g[it.second]){
			int x=w.x,y=w.y;
			Merge(x+n,y),Merge(x,y+n);
			//cout<<"O:"<<x<<' '<<y<<' '<<gf(x)<<' '<<gf(y)<<endl;
			if(gf(x)==gf(y)){
				ans--;
				break;
			}
		}
		while(top>tp)fa[st[top][0]]=st[top][0],size[st[top][1]]-=size[st[top][0]],top--;
	}
	cout<<ans;
}