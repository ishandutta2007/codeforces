#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define B 400
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],Q;
int L[B],R[B],len,blocks,pos[N],f[N];
int add[N];
int nd[N];
void Renew(int x){
	nd[x]=0;
	for(int i=L[x];i<=R[x];++i){
		a[i]=max(a[i]-add[x],1);
		f[i]=(a[i]<L[x]?a[i]:f[a[i]]);
		nd[x]|=f[i]!=a[i];
	}
	add[x]=0;
}
void Change(int l,int r,int w){
	int x=pos[l],y=pos[r];
	if(x==y){
		for(int i=l;i<=r;++i)a[i]=max(a[i]-w,1);
		Renew(x);
	}
	else{
		for(int i=l;i<=R[x];++i)a[i]=max(a[i]-w,1);
		for(int i=L[y];i<=r;++i)a[i]=max(a[i]-w,1);
		Renew(x),Renew(y);
		for(int i=x+1;i<y;++i){
			add[i]+=w;
			if(nd[i])Renew(i);
		}
	}
}
inline int get_f(int x){
	return x==1?0:max(1,f[x]-add[pos[x]]);
}
int Query(int x,int y){
	while(get_f(x)^get_f(y)){
		if(get_f(x)<get_f(y))swap(x,y);
		x=get_f(x);
	}
	static int vis[N];
	static vector<int> bin;
	for(auto x:bin)vis[x]=0;
	bin.clear();
	Renew(pos[x]),Renew(pos[y]);
	int lim=get_f(x);
	while(x^lim){
		bin.push_back(x);
		vis[x]=1,x=a[x];	
	}
	vis[x]=1,bin.push_back(x);
	while(233){
		if(vis[y])return y;
		y=a[y];
	}
}
int main(){
	n=read(),Q=read();
	for(int i=2;i<=n;++i){
		a[i]=read();	
	}
	len=ceil(sqrt(n));
	blocks=n/len+(n%len!=0);
	for(int i=1;i<=blocks;++i){
		L[i]=max(2,(i-1)*len+1),R[i]=min(i*len,n);
		for(int j=L[i];j<=R[i];++j)pos[j]=i;
		Renew(i);
	}
	while(Q--){
		int opt=read();
		if(opt==1){
			int x=read(),y=read(),z=read();
			Change(x,y,z);
		}
		else{
			int u=read(),v=read();
			printf("%d\n",Query(u,v));
		}
	}
	return 0;
}