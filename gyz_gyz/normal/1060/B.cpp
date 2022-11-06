#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 600000
#define ll long long
using namespace std;
int ans;ll n,x;
int main(){
	scanf("%I64d",&n);x=9;
	while(x<=n)n-=x,x*=10,ans+=9;
	while(n)ans+=n%10,n/=10;
	printf("%d",ans);
}