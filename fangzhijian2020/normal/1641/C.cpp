#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int Mxdt=100000,mod=998244353,INF=1e9;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2),*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,q,opt,l,r,x,a[300005];
struct node{
	int l,r;
	bool operator<(const node&a)const{
		return r<a.r;
	}
};
set<node>s;set<node>::iterator it;
void add(int x,int v){
	for(;x<=n;x+=x&-x)a[x]=min(a[x],v);
}
int ask(int x){
	int ans=n+1;
	for(;x;x-=x&-x)ans=min(ans,a[x]);
	return ans;
}
int tp[800005],sum[800005],tag[800005];
void Tag(int k){
	tp[k]=1;tag[k]=1;
}
void pushdown(int k){
	if(tag[k]){
		Tag(k<<1);Tag(k<<1|1);
		tag[k]=0;
	}
}
void pushup(int k){
	tp[k]=(tp[k<<1]&tp[k<<1|1]);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
void change(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R){Tag(k);return;}
	int mid=l+r>>1;pushdown(k);
	if(L<=mid)change(k<<1,l,mid,L,R);
	if(R>mid)change(k<<1|1,mid+1,r,L,R);
	pushup(k);
}
void Change(int k,int l,int r,int x){
	if(l==r){sum[k]=1;return;}
	int mid=l+r>>1;pushdown(k);
	if(x<=mid)Change(k<<1,l,mid,x);
	else Change(k<<1|1,mid+1,r,x);
	pushup(k);
}
int query(int k,int l,int r,int x){
	if(l==r){
		if(sum[k])return 1;
		if(tp[k])return 0;
		return -1;
	}
	int mid=l+r>>1;pushdown(k);
	if(x<=mid)return query(k<<1,l,mid,x);
	else return query(k<<1|1,mid+1,r,x);
}
int Query(int k,int l,int r,int L,int R){
	if(L>R)return 1;
	if(L<=l&&r<=R)return tp[k];
	int mid=l+r>>1,ans=1;pushdown(k);
	if(L<=mid)ans&=Query(k<<1,l,mid,L,R);
	if(R>mid)ans&=Query(k<<1|1,mid+1,r,L,R);
	return ans;
}
int findl(int id){
	int l=1,r=id;
	while(l<=r){
		int mid=l+r>>1;
		if(Query(1,1,n,mid,id-1))r=mid-1;
		else l=mid+1;
	}
	return r+1;
}
int findr(int id){
	int l=id,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(Query(1,1,n,id+1,mid))l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;++i)a[i]=n+1;
	for(int i=1;i<=q;++i){
		opt=read();
		if(opt==0){
			l=read();r=read();x=read();
			if(x==0)change(1,1,n,l,r);
			else{
				if(ask(n-l+1)>r){
					while(1){
						it=s.lower_bound((node){l,r});
						if(it==s.end())break;
						if((*it).l<=l){
							int tmp=(*it).l;s.erase(it);
						}
						else break;
					}
					s.insert((node){l,r});
				}
				add(n-l+1,r);
			}
		}
		else{
			x=read();int tmp=query(1,1,n,x);
			if(tmp!=-1)puts(tmp?"YES":"NO");
			else{
				int L=findl(x),R=findr(x);
				while(1){
					it=s.upper_bound((node){0,R});
					if(it==s.begin())break;--it;
					if((*it).r<x)break;
					if((*it).l>x)s.erase(it);
					else{
						if((*it).l>=L)tmp=1;break;
					}
				}
				if(tmp==1){
					puts("YES");Change(1,1,n,x);
				}
				else{
					puts("N/A");
				}
			}
		}
	}
	return 0;
}