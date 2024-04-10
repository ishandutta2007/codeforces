#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int N=500000,mod=1e9+7;
vector<int> g[N+5];
vector<pr> e[N+5];
int jc[N+5],n,a[N+5],fa[N+5],d[N+5],fir[N+5],lst[N+5],cnt[N+5][2];
int ff[N+5],out[N+5],in[N+5],ans=1;
//0:
//1: 
int LCA(int x,int y){
	while(x!=y){
		if(d[x]<d[y])swap(x,y);
		x=fa[x];
	}
	return x;
}
void dfs(int x,int f){
	d[x]=d[f]+1,fa[x]=f;
	for(int y:g[x]){
		if(y==f)continue;
		dfs(y,x);
	}
}
int gf(int x){
	return x==ff[x]?x:ff[x]=gf(ff[x]);
}
void Merge(int x,int y){
	x=gf(x),y=gf(y);
	ff[x]=y;
	if(x==y)puts("0"),exit(0);
}
int main(){
	jc[0]=1,cin>>n;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==i)puts("0"),exit(0);
		if(!a[i])continue;
		int p=LCA(i,a[i]);
		vector<int> vert;
		int x=i;
		while(x!=p){
			vert.push_back(x);
			x=fa[x];
		}
		vert.push_back(p);
		vector<int> tmp;
		x=a[i];
		while(x!=p){
			tmp.push_back(x);
			x=fa[x];
		}
		reverse(tmp.begin(),tmp.end());
		for(int i:tmp)vert.push_back(i);
		for(int i=0;i+1<vert.size();i++){
			int x=vert[i],y=vert[i+1];
			if(fa[x]==y){
				cnt[x][0]++;
				if(cnt[x][0]>1)puts("0"),exit(0);
			}
			else {
				cnt[y][1]++;
				if(cnt[y][1]>1)puts("0"),exit(0);
			}
		}
		fir[i]=vert[1];
		lst[a[i]]=vert[vert.size()-2];
		for(int i=1;i+1<vert.size();i++){
			int x=vert[i-1],y=vert[i],z=vert[i+1];
			e[y].push_back(pr(x,z));
		}
	}
	for(int i=1;i<=n;i++){
		for(int x:g[i])out[x]=in[x]=0,ff[x]=x;
		for(auto &[x,y]:e[i]){
			out[x]++,in[y]++,Merge(x,y);
			if(out[x]>1||in[y]>1)puts("0"),exit(0);
		}
		if(lst[i]&&out[lst[i]])puts("0"),exit(0);
		if(fir[i]&&in[fir[i]])puts("0"),exit(0);
		int deg=0,cnt=0;
		for(int x:g[i]){
			if(gf(x)!=x)continue;
			cnt++;
			if(fir[i]&&gf(fir[i])==x)continue;
			if(lst[i]&&gf(lst[i])==x)continue;
			deg++;
		}
		if(cnt>1&&fir[i]&&lst[i]&&gf(fir[i])==gf(lst[i]))puts("0"),exit(0);
		ans=1ll*ans*jc[deg]%mod;
	}
	cout<<ans;
}