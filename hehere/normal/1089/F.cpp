#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,v[2],cnt;
void getfac(int val){
	int i;
	for(i=2;i*i<=val && cnt<2;++i){
		if(val%i==0){
			while(val%i==0) val/=i;
			v[cnt++]=i;
		}
	}
	if(val>1 && cnt<2) v[cnt++]=val;
}
int pwm(LL val,LL tms,LL md){
	LL ret=1ll;
	while(tms){
		if(tms&1ll) ret=val*ret%md;
		val=val*val%md;
		tms>>=1ll;
	}
	return ret%md;
}
int gcd(int x,int y){
	if(!x || !y) return x?x:y;
	return gcd(y,x%y);
}
void out(int u,int v){
	if(!u){
		printf("%d %d\n",u,v);
		return;
	}
	int d=gcd(u,v);
	printf("%d %d\n",u/d,v/d);
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	getfac(n);
	if(cnt==1 || v[0]==v[1]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int v1=v[0],v2=v[1];
	int tar=(n-1)%v2;
	int ml=(LL)pwm(v1,v2-2,v2)*(LL)tar%(LL)v2;
	int mr=(n-1-v1*ml)/v2;
	printf("2\n");
	out(ml,n/v1);
	out(mr,n/v2);
	return 0;
}