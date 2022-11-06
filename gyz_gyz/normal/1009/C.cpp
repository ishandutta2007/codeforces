#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int m;ll n,p,x,an0,an1,an2;long double ans;
int main(){
	scanf("%I64d%d",&n,&m);p=(n+1)/2;
	rep(i,1,m){
		scanf("%I64d",&x);an0+=x;
		scanf("%I64d",&x);
		if(x<0){
			an2+=x*((p-1)*p+(n/2)*((n&1)==0));
		}else an1+=x*(n-1);
	}
	ans=an2;ans/=n;ans+=an0+an1*0.5;
	printf("%.15lf",(double)ans);
}