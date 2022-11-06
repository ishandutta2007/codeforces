#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int T,n,m,a[200005],b[200005],ta[200005],tb[200005];long long suma,sumb;
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();suma=sumb=0;
		for(int i=1;i<=n;++i){
			a[i]=read();b[i]=read();
			suma+=a[i];sumb+=b[i];
		}
		for(int i=1;i<=n;++i){
			if(a[i]>=m){
				suma-=m;ta[i]=m;tb[i]=0;
			}
			else{
				suma-=a[i];ta[i]=a[i];
				sumb-=(m-a[i]);tb[i]=(m-a[i]);
			}
		}
		for(int i=1;i<=n;++i){
			if(suma<sumb){
				int x=min(b[i]-tb[i],ta[i]);
				if(suma+x<=sumb-x){
					suma+=x;sumb-=x;
					ta[i]-=x;tb[i]+=x;
				}
				else{
					x=(sumb-suma)/2;
					suma+=x;sumb-=x;
					ta[i]-=x;tb[i]+=x;
				}
			}
		}
		cout<<abs(suma-sumb)<<"\n";
		for(int i=1;i<=n;++i){
			cout<<ta[i]<<' '<<tb[i]<<"\n";
		}
	}
	return 0;
}