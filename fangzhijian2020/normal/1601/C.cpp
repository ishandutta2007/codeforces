#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
//	return getchar();
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,m,a[1000005],b[1000005],tot=0,tmp[2000005],tots,s[2000005],st[1000005],sp[1000005];long long ans=0;
int root[1000005],ls[25000005],rs[25000005],Size[25000005];
void change(int&p,int q,int l,int r,int x){
	p=++tot;Size[p]=Size[q]+1;ls[p]=ls[q];rs[p]=rs[q];
	if(l==r)return;int mid=l+r>>1;
	if(x<=mid)change(ls[p],ls[q],l,mid,x),ans+=Size[rs[q]];
	else change(rs[p],rs[q],mid+1,r,x);
}
int query(int p,int q,int l,int r,int L,int R){
	if(L>R)return 0;if(!p)return 0;
	if(L<=l&&r<=R){return Size[p]-Size[q];}
	int mid=l+r>>1,ans=0;
	if(L<=mid)ans+=query(ls[p],ls[q],l,mid,L,R);
	if(R>mid)ans+=query(rs[p],rs[q],mid+1,r,L,R);
	return ans;
}
int query(int p,int l,int r,int L,int R){
	if(L>R)return 0;if(!p)return 0;
	if(L<=l&&r<=R){return Size[p];}
	int mid=l+r>>1,ans=0;
	if(L<=mid)ans+=query(ls[p],l,mid,L,R);
	if(R>mid)ans+=query(rs[p],mid+1,r,L,R);
	return ans;
}
int query(int p,int l,int r,int x){
	if(!p)return 0;
	if(l==r){return 0;}
	int mid=l+r>>1;
	if(x<=mid)return query(ls[p],l,mid,x)+Size[rs[p]];
	else return query(rs[p],mid+1,r,x)-Size[ls[p]];
	return ans;
}
void solve(int l,int r,int L,int R){
	if(l>r)return;
	if(L==R){
		int x=root[L];
		for(int i=l;i<=r;++i){
			ans+=query(x,1,tots,b[i])+s[b[i]-1];
		}
		return;
	}
	int mid=l+r>>1,Min=1e9,id=L;
	for(int i=L;i<=R;++i){
		st[i]=(i==L?:st[i-1])+(a[i]>b[mid]);
	}
	sp[R+1]=0;
	for(int i=R;i>=L;--i){
		sp[i]=sp[i+1]+(a[i]<b[mid]);
	}
	for(int i=L;i<=R;++i){
		int tmp=st[i]+sp[i+1];
		if(tmp<Min){Min=tmp;id=i;}
	}
	ans+=s[b[mid]-1]+query(root[id],1,tots,b[mid]);solve(l,mid-1,L,id);solve(mid+1,r,id,R);
}
int main(){
	T=read()+1;
	while(--T){
		tot=0;ans=0;tots=0;n=read();m=read();
		for(int i=1;i<=n;++i)a[i]=read(),tmp[++tots]=a[i];
		for(int i=1;i<=m;++i)b[i]=read(),tmp[++tots]=b[i];
		sort(b+1,b+m+1);sort(tmp+1,tmp+tots+1);
		tots=unique(tmp+1,tmp+tots+1)-tmp-1;
		for(int i=1;i<=tots;++i)s[i]=0;
		for(int i=1;i<=n;++i)a[i]=lower_bound(tmp+1,tmp+tots+1,a[i])-tmp,++s[a[i]];
		for(int i=1;i<=m;++i)b[i]=lower_bound(tmp+1,tmp+tots+1,b[i])-tmp;
		for(int i=1;i<=tots;++i)s[i]+=s[i-1];
		for(int i=1;i<=n;++i)change(root[i],root[i-1],1,tots,a[i]);
		solve(1,m,0,n);cout<<ans<<"\n";
	}
	return 0;
}