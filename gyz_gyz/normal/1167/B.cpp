#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[7],t[7];
const int p[]={4,8,15,16,23,42};
int main(){
	rep(i,2,5){
		printf("? 1 %d\n",i);
		fflush(stdout);scanf("%d",&t[i]);
		if(i==2)a[1]=t[i];else a[1]=__gcd(a[1],t[i]);
	}int x=-1;
	rep(i,0,5)if(!(a[1]%p[i]))x=max(x,p[i]);a[1]=x;
	rep(i,2,5)a[i]=t[i]/a[1];
	rep(i,0,5)if(!count(a+1,a+6,p[i])){
		a[6]=p[i];break;
	}
	printf("!");
	rep(i,1,6)printf(" %d",a[i]);
}