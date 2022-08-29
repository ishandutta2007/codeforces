#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define re register
using namespace std;
int t,n,a,b,c;
double ans;
signed main(){
scanf("%d",&n);
for(re int i=1;i<=n;++i)ans+=(double)1/i;
printf("%.10lf",ans);
	}