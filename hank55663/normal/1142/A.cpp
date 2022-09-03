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
	LL n,k;
	scanf("%lld %lld",&n,&k);
	LL a,b;
	scanf("%lld %lld",&a,&b);
	LL len = n*k;
	LL mingcd=1e18,maxgcd=0;
	for(int i = 0;i<n;i++){
		LL l = a+b+i*k;
		//printf("%lld %lld\n",l,len);
		LL gcd=__gcd(l,len);
		//if(l!=0){
		maxgcd=max(gcd,maxgcd);
		mingcd=min(gcd,mingcd);
		//}
		l=k-a+b+i*k;
		gcd=__gcd(l,len);
		maxgcd=max(gcd,maxgcd);
		mingcd=min(gcd,mingcd);
		l=k-b+a+i*k;
		gcd=__gcd(l,len);
		maxgcd=max(gcd,maxgcd);
		mingcd=min(gcd,mingcd);
		l=k-a+k-b+i*k;
		gcd=__gcd(l,len);
		maxgcd=max(gcd,maxgcd);
		mingcd=min(gcd,mingcd);
	}
	printf("%lld %lld\n",len/maxgcd,len/mingcd);
}