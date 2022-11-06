#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 300000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int T,d;double l,r,m;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&d);
		if(!d){
			printf("Y 0.000000000 0.000000000\n");continue;
		}
		if(d<4){
			printf("N\n");continue;
		}
		l=d*0.5;r=d-1;m=(l+r)/2;
		for(;r-l>1e-9;m=(l+r)/2){
			if(m*(d-m)>=d)l=m;else r=m;
		}
		printf("Y %.9lf %.9lf\n",m,d-m);
	}
}