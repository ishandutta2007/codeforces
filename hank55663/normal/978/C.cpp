#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	LL a[200005];
	a[0]=0;
	for(int i =1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	while(m--){
		LL x;
		scanf("%lld",&x);
		int d=lower_bound(a,a+n+1,x)-a;
		x-=a[d-1];
		printf("%d %lld\n",d,x);
	}
}