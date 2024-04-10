#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,k;
long double ans,fac[100010];
long double C(int n,int m){
	return fac[n]-fac[m]-fac[n-m];
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		fac[i]=fac[i-1]+log(i*1.0);
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			int x=n*(i+j)-i*j;
			if(x>k)break;
			ans=min(ans+exp(C(n,i)+C(n,j)+C(k,x)-C(m,x)),1e99L);
		}
	}
	if(ans>=1e99){
		printf("1e99\n");
		return 0;
	}
	double myh=ans;
	printf("%.10lf\n",myh);
	return 0;
}