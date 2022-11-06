#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n;ll x,y;
ll c(int x,int y){ll ans=1;
	if((y>x)||(y<0))return 0;
	rep(i,1,y)ans=ans*(x-i+1)/i;
	rep(i,1,y)ans*=9;return ans;
}
ll cal(ll x){ll y=1,ans=0;int z=3;
	rep(i,1,18)y*=10;
	dep(i,18,0){
		if(y<=x){
			ans+=c(i,z);
			ans+=(x/y)*(c(i,z-1)+c(i,z-2)+c(i,z-3));
			z--;x-=(x/y)*y;
		}y/=10;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%I64d%I64d",&x,&y);
		printf("%I64d\n",cal(y+1)-cal(x));
	}
}