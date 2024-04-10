#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000,N=200000,mod=1e9+7;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,x,q,l,r,prime[200005],tot,vis[200005],P[50],lastans;
struct node{int x,num;};vector<node>v[200005];
int root[100005],t[40000005],ls[40000005],rs[40000005];
void change(int&p,int l,int r,int L,int R,int x){
	int now=++tot;t[now]=t[p];
	ls[now]=ls[p];rs[now]=rs[p];p=now;
	if(L<=l&&r<=R){t[now]=1ll*t[now]*x%mod;return;}
	int mid=l+r>>1;
	if(L<=mid)change(ls[p],l,mid,L,R,x);
	if(R>mid)change(rs[p],mid+1,r,L,R,x);
}
int query(int p,int l,int r,int x){
	if(!p)return 1;if(l==r)return t[p];
	int mid=l+r>>1;
	if(x<=mid)return 1ll*t[p]*query(ls[p],l,mid,x)%mod;
	else return 1ll*t[p]*query(rs[p],mid+1,r,x)%mod;
}
int main(){
	for(int i=2;i<=N;++i){
		if(!vis[i]){
			prime[++tot]=i;vis[i]=i;
			v[i].push_back((node){0,N});
		}
		for(int j=1;j<=tot;++j){
			if(i*prime[j]>N)break;
			vis[i*prime[j]]=prime[j];
			if(!(i%prime[j]))break;
		}
	}
	t[tot=0]=1;n=read();
	for(int i=1;i<=n;++i){
		x=read();root[i]=root[i-1];
		while(x!=1){
			int p=vis[x],num=0;P[0]=1;
			while(!(x%p)){
				x/=p;++num;
				P[num]=1ll*P[num-1]*p%mod;
			}
			int r=i,mx=0;
			while(v[p].size()&&v[p].back().num<=num){
				change(root[i],1,n,v[p].back().x+1,r,P[num-mx]);
				mx=v[p].back().num;r=v[p].back().x;v[p].pop_back();
			}
			change(root[i],1,n,v[p].back().x+1,r,P[num-mx]);
			v[p].push_back((node){i,num});
		}
	}
	q=read();
	for(int i=1;i<=q;++i){
		l=(read()+lastans)%n+1;
		r=(read()+lastans)%n+1;if(l>r)swap(l,r);
		cout<<(lastans=query(root[r],1,n,l))<<"\n";
	}
	return 0;
}