#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E{
	int to,val;
};
int n,m,used[200005],size[200005],inv[200005],pw10[200005];
ll ans=0;
vector<E> g[200005];
int Exgcd(int a,int b,int &x,int &y){
	if(!b)return x=1,y=0,a;
	int ret=Exgcd(b,a%b,x,y),t=x;
	return x=y,y=t-(a/b)*y,ret;
}
void Getsize(int x,int fa){
	size[x]=1;
	for(E i:g[x]){
		int y=i.to;
		if(used[y]||y==fa)continue;
		Getsize(y,x),size[x]+=size[y];
	}
}
void Findct(int x,int fa,int all,int &ct,int &mi){
	int mx=all-size[x];
	for(E i:g[x]){
		int y=i.to;
		if(used[y]||y==fa)continue;
		Findct(y,x,all,ct,mi),mx=max(mx,size[y]);
	}
	if(mx<mi)mi=mx,ct=x;
}
map<int,int> mp1,mp2;
void dfs1(int x,int fa,int val,int dep){
	ans+=mp2[1ll*(m-val)%m*inv[dep]%m];
	for(E i:g[x]){
		int y=i.to;
		if(used[y]||y==fa)continue;
		dfs1(y,x,(10ll*val+i.val)%m,dep+1);
	}
}
void dfs2(int x,int fa,int val,int dep){
	ans+=mp1[(m-val)%m];
	for(E i:g[x]){
		int y=i.to;
		if(used[y]||y==fa)continue;
		dfs2(y,x,(val+1ll*i.val*pw10[dep])%m,dep+1);
	}
}
void add1(int x,int fa,int val,int dep){
	mp1[1ll*val*inv[dep]%m]++;
	for(E i:g[x]){
		int y=i.to;
		if(used[y]||y==fa)continue;
		add1(y,x,(10ll*val+i.val)%m,dep+1);
	}
}
void add2(int x,int fa,int val,int dep){
	mp2[val]++;
	for(E i:g[x]){
		int y=i.to;
		if(used[y]||y==fa)continue;
		add2(y,x,(val+1ll*i.val*pw10[dep])%m,dep+1);
	}
}
void Dianfenzhi(int x){
	int ct=0,mi=1e9,y;
	Getsize(x,0),Findct(x,0,size[x],ct,mi),used[ct]=1;
	mp1.clear(),mp2.clear(),mp1[0]=mp2[0]=1;
	for(E i:g[ct]){
		if(used[y=i.to])continue;
		dfs1(y,ct,i.val,1),dfs2(y,ct,i.val,1);
		add1(y,ct,i.val,1),add2(y,ct,i.val,1);
	}
	for(E i:g[ct])if(!used[y=i.to])Dianfenzhi(y);
}
int main(){
	scanf("%d%d",&n,&m),inv[0]=1,Exgcd(10,m,inv[1],inv[2]),inv[1]=(inv[1]%m+m)%m;
	for(int i=2;i<=n;i++)inv[i]=1ll*inv[i-1]*inv[1]%m;
	pw10[0]=1;
	for(int i=1;i<=n;i++)pw10[i]=10ll*pw10[i-1]%m;
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),x++,y++,z%=m,g[x].push_back({y,z}),g[y].push_back({x,z});
	Dianfenzhi(1),printf("%lld\n",ans);
}