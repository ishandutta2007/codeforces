#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,p,q,t1[135],t2[135];unsigned int ans,vis[135],tmp[135];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
unsigned int C(int n,int m){
	if(vis[m])return tmp[m];
	vis[m]=1;tmp[m]=1;
	for(int i=1;i<=m;++i)t1[i]=i,t2[i]=n-i+1;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			if(t1[i]==1)break;
			if(t2[j]!=1){
				int GCD=gcd(t1[i],t2[j]);
				t1[i]/=GCD;t2[j]/=GCD;
			}
		}
	}
	for(int i=1;i<=m;++i)tmp[m]=tmp[m]*t2[i];
	return tmp[m];
}
int main(){
	n=read();p=read();q=read();
	for(int i=1;i<=q;++i){
		unsigned int sum=0,tmp=1;
		for(int j=0;j<=min(p,n-1);++j){
			sum+=C(n,j)*tmp;tmp=tmp*i;
		}
		ans^=sum*i;
	}
	cout<<ans<<"\n";
	return 0;
}