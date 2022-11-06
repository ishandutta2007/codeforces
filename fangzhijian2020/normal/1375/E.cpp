#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,a[1005],tot,x[1000005],y[1000005],tp[1005],tots,sum[1005],pos[1005];
void add(int A,int B){++tot;x[tot]=A;y[tot]=B;swap(a[A],a[B]);}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),tp[++tots]=a[i];
	sort(tp+1,tp+tots+1);
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(tp+1,tp+tots+1,a[i])-tp;
		++sum[a[i]];a[i]+=sum[a[i]]-1;pos[a[i]]=i;
	}
	for(int i=n;i;--i){
		int tmp=a[i];
		for(int t=tmp+1;t<=i;++t)add(pos[t],i);
		for(int j=1;j<i;++j)pos[a[j]]=j;
		
	}
	cout<<tot<<"\n";
	for(int i=1;i<=tot;++i){
		cout<<x[i]<<" "<<y[i]<<"\n";
	}
	return 0;
}