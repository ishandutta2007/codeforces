#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
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
	int n;
	scanf("%d",&n);
	LL a[300005];
	for(int i= 0;i<n;i++)
	scanf("%lld",&a[i]);
	LL less=0,sum=0;
	for(int i =0;i<n;i++){
		LL num=min(less,a[i]/2);
		less-=num;
		a[i]-=num*2;
		sum+=num;
		sum+=a[i]/3;
		less+=a[i]%3;
	//	printf("%lld %lld\n",sum,less);
	}
	printf("%lld\n",sum);
}
//1 1 3 4 5 5 9
// 0 2 1 1 0 4
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc