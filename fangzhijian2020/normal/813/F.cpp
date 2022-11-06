#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,Q,x,y;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		if(x==a.x)return y<a.y;return x<a.x;
	}
}q[2000005];vector<node>v[400005];
map<node,int>mp;map<node,int>::iterator it;
void change(int k,int l,int r,int L,int R,node x){
	if(L<=l&&r<=R){v[k].push_back(x);return;}
	int mid=l+r>>1;
	if(L<=mid)change(k<<1,l,mid,L,R,x);
	if(R>mid)change(k<<1|1,mid+1,r,L,R,x);
}
int fa[100005],size[100005],f[100005],t[100005],tot,ans=1;
int getfzj(int x){
	if(x==fa[x])return x;
	int tmp=getfzj(fa[x]);
	f[x]=f[fa[x]]^t[x];return tmp;
}
void Merge(int x,int y){
	int fx=getfzj(x),fy=getfzj(y);
	if(fx!=fy){
		if(size[fx]>size[fy])swap(fx,fy);
		fa[fx]=fa[fy];size[fy]+=size[fx];t[fx]=f[x]^f[y]^1;
		q[++tot]=(node){fx,fy};
	}
	else{
		if(!(f[x]^f[y]))ans=0;
	}
}
void back(int now){
	while(tot>now){
		fa[q[tot].x]=q[tot].x;f[q[tot].x]=0;
		size[q[tot].y]-=size[q[tot].x];--tot;
	}
}
void query(int k,int l,int r){
	int mid=l+r>>1,now=tot,opt=ans;
	for(int i=0;i<v[k].size();++i)Merge(v[k][i].x,v[k][i].y);
	if(l==r){puts(ans?"YES":"NO");back(now);ans=opt;return;}
	query(k<<1,l,mid);query(k<<1|1,mid+1,r);back(now);ans=opt;
}
int main(){
	n=read();Q=read();
	for(int i=1;i<=Q;++i){
		x=read();y=read();
		if(mp[(node){x,y}]==0)mp[(node){x,y}]=i;
		else{
			change(1,1,Q,mp[(node){x,y}],i-1,(node){x,y});mp[(node){x,y}]=0;
		}
	}
	for(it=mp.begin();it!=mp.end();++it){
		if(it->second){
			change(1,1,Q,it->second,Q,it->first);
		}
	}
	for(int i=1;i<=n;++i)fa[i]=i,size[i]=1;query(1,1,Q);
	return 0;
}