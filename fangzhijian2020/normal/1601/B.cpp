#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353,INF=1e9;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,a[300005],b[300005],pre[300005],s[300005],top;
struct node{
	int x,v,id;
	void merge(const node a,const node b){
		if(a.v<b.v){
			x=a.x;v=a.v;id=a.id;
		}
		else{
			x=b.x;v=b.v;id=b.id;
		}
	}
	void clear(){
		v=INF;x=id=0;
	}
}t[1200005],tag[1200005];
void build(int k,int l,int r){
	tag[k].clear();
	if(l==r){
		t[k].id=l;t[k].x=0;t[k].v=INF;
		if(l==n){t[k].id=l;t[k].x=0;t[k].v=0;}
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	t[k].merge(t[k<<1],t[k<<1|1]);//cout<<k<<" "<<l<<' '<<r<<";"<<t[k].v<<";\n";
}
node min(const node a,const node b){
	node c=a;
	if(a.v>b.v){
		c.v=b.v;c.x=b.x;
	}
	return c;
}
void Tag(int k,node v){
	if(t[k].v!=(INF<<1)){
		tag[k]=min(tag[k],v);
		t[k]=min(t[k],v);
	}
}
void pushdown(int k){
	if(tag[k].v!=INF){
//		cout<<k<<";"<<t[k].v<<":::\n";
		Tag(k<<1,tag[k]);
		Tag(k<<1|1,tag[k]);
		tag[k].clear();
	}
}
void change(int k,int l,int r,int L,int R,node v){
	if(L<=l&&r<=R){Tag(k,v);return;}
	int mid=l+r>>1;pushdown(k);
	if(L<=mid)change(k<<1,l,mid,L,R,v);
	if(R>mid)change(k<<1|1,mid+1,r,L,R,v);
	t[k].merge(t[k<<1],t[k<<1|1]);
}
void Del(int k){t[k].v=(INF<<1);}
void del(int k,int l,int r,int x){
	if(l==r){Del(k);return;}
	int mid=l+r>>1;pushdown(k);
	if(x<=mid)del(k<<1,l,mid,x);
	else del(k<<1|1,mid+1,r,x);
	t[k].merge(t[k<<1],t[k<<1|1]);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	build(1,0,n);
	
	for(int i=n;~i;--i){
		node tmp=t[1];pre[tmp.id]=tmp.x;
		del(1,0,n,tmp.id);if(tmp.id==0)break;
		int now=tmp.id+b[tmp.id];++tmp.v;tmp.x=tmp.id;
		change(1,0,n,max(0,now-a[now]),now-1,tmp);
	}
	int now=0;
	while(now!=n){
		s[++top]=now;
		now=pre[now];
		if(now==0){
			puts("-1");return 0;
		}
	}
	cout<<top<<"\n";
	for(int i=top;i;--i){
		cout<<s[i]<<" ";
	}
	puts("");
	return 0;
}