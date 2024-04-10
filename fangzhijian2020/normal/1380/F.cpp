#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=500000,mod=998244353;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,x,y,opt,a[N+5];char c[N+5];
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
struct node{
	int a[2][2];
	void clear(){
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)a[i][j]=0;
	}
}t[(N<<2)+5];
node mul(node x,node y){
	node t;t.clear();
	for(int i=0;i<2;++i){
		for(int k=0;k<2;++k){
			for(int j=0;j<2;++j){
				Add(t.a[i][j],1ll*x.a[i][k]*y.a[k][j]%mod);
			}
		}
	}
	return t;
}
node solve(int x){
	node t;t.clear();
	t.a[0][0]=a[x]+1;t.a[0][1]=1;
	if(a[x-1]==1)t.a[1][0]=9-a[x];
	return t;
}
void build(int k,int l,int r){
	if(l==r){t[k]=solve(l);return;}
	int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	t[k]=mul(t[k<<1],t[k<<1|1]);
}
void change(int k,int l,int r,int x){
	if(l==r){t[k]=solve(l);return;}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x);
	else change(k<<1|1,mid+1,r,x);
	t[k]=mul(t[k<<1],t[k<<1|1]);
}
int main(){
	n=read();m=read();scanf("%s",c+1);
	for(int i=1;i<=n;++i)a[i]=c[i]-'0';
	build(1,1,n);
	for(int i=1;i<=m;++i){
		x=read();y=read();opt=a[x]==1;
		a[x]=y;change(1,1,n,x);
		if((opt||y==1)&&x!=n)change(1,1,n,x+1);
		printf("%d\n",t[1].a[0][0]);
	}
	return 0;
}