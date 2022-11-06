#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int nu,we;}f[N][22];
int a[N],we[N],ansn,g[N],n;
Info que(Info x,Info y){if (x.nu>y.nu)return x;return y;}
Info que1(int l,int r){
	int x=g[r-l+1];
	return que(f[l][x],f[r-(1<<x)+1][x]);
}
void work(int l,int r){
	if (l>r)return ;
	Info x=que1(l,r);
	if (x.we-l<r-x.we){
		for (int i=l;i<x.we;i++)if (we[x.nu-a[i]]>x.we&&we[x.nu-a[i]]<=r) ansn++;
	}else{
		for (int i=x.we+1;i<=r;i++)if (we[x.nu-a[i]]>=l&&we[x.nu-a[i]]<x.we) ansn++;		
	}
	work(l,x.we-1);work(x.we+1,r);
}
int main(){
	read(n);
	for (int i=1;i<=n;i++){read(a[i]);we[a[i]]=i;}
	for (int i=1;i<=n;i++){f[i][0].nu=a[i];f[i][0].we=i;}
	g[1]=0;
	for (int i=2;i<=n;i++)g[i]=g[i/2]+1;
	for (int i=2,j=1;i<=n;i*=2,j++)
		for (int k=1;k+i-1<=n;k++)f[k][j]=que(f[k][j-1],f[k+(1<<(j-1))][j-1]);
	work(1,n);cout<<ansn<<endl;
	return 0;
}