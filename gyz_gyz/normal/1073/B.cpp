#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,x,t,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);a[x]=i;
	}
	rep(i,1,n){
		scanf("%d",&x);
		printf("%d ",max(0,a[x]-t));
		t=max(a[x],t);
	}
}