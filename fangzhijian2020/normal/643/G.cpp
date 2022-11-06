#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=150000;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,p,a[N+5],opt,x,y;
struct node{
	int a[6],num[6],cnt,lazy;
	node operator+(const node&x){
		node t=x;t.lazy=0;
		for(int i=1;i<=cnt;++i){
			int opt=0;
			for(int j=1;j<=t.cnt;++j){
				if(a[i]==t.a[j]){
					t.num[j]+=num[i];opt=1;
				}
			}
			if(opt)continue;
			if(t.cnt<p){t.a[++t.cnt]=a[i];t.num[t.cnt]=num[i];continue;}
			int Min=1e9;opt=0;
			for(int j=1;j<=t.cnt;++j){
				if(t.num[j]<Min){Min=t.num[j];opt=j;}
			}
			if(num[i]<=Min){
				for(int j=1;j<=t.cnt;++j)t.num[j]-=num[i];
			}
			else{
				int tmp=t.num[opt];
				t.a[opt]=a[i];t.num[opt]=num[i];
				for(int j=1;j<=t.cnt;++j)t.num[j]-=tmp;
			}
		}
		return t;
	}
}t[(N<<2)+5];
void tag(int k,int l,int r,int id){
	t[k].cnt=1;t[k].a[1]=id;t[k].num[1]=r-l+1;t[k].lazy=id;
}
void pushup(int k){t[k]=t[k<<1]+t[k<<1|1];}
void pushdown(int k,int l,int r){
	if(t[k].lazy){
		int mid=l+r>>1;
		tag(k<<1,l,mid,t[k].lazy);
		tag(k<<1|1,mid+1,r,t[k].lazy);
		t[k].lazy=0;
	}
}
void build(int k,int l,int r){
	if(l==r){t[k].cnt=1;t[k].a[1]=a[l];t[k].num[1]=1;return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int L,int R,int id){
	if(L<=l&&r<=R){tag(k,l,r,id);return;}
	int mid=l+r>>1;pushdown(k,l,r);
	if(L<=mid)change(k<<1,l,mid,L,R,id);
	if(R>mid)change(k<<1|1,mid+1,r,L,R,id);
	pushup(k);
}
node query(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[k];
	int mid=l+r>>1;pushdown(k,l,r);
	if(R<=mid)return query(k<<1,l,mid,L,R);
	if(L>mid)return query(k<<1|1,mid+1,r,L,R);
	return query(k<<1,l,mid,L,R)+query(k<<1|1,mid+1,r,L,R);
}
int main(){
	n=read();m=read();p=100/read();
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;++i){
		opt=read();x=read();y=read();
		if(opt==1)change(1,1,n,x,y,read());
		else{
			node ans=query(1,1,n,x,y);
			cout<<ans.cnt<<" ";
			for(int j=1;j<=ans.cnt;++j){
				cout<<ans.a[j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}