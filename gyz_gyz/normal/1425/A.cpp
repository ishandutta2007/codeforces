#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N];
ll cal(ll x){
	if(x<=100000)return a[x];
	if(x%4==2)return x-cal(x/2);
	else return x-cal(x-1);
}
int main(){int t;
	rep(i,1,100000){
		if(i&1)a[i]=i-a[i-1];
		else a[i]=max(i-a[i-1],i-a[i/2]);
	}
	scanf("%d",&t);
	rep(i,1,t){ll n;
		scanf("%lld",&n);
		printf("%lld\n",cal(n));
	}
}