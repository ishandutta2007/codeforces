#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,ans;ll m;
int main(){
	scanf("%d%I64d",&n,&m);
	rep(i,0,n)if(1ll*i*(i-1)/2>=m){ans=i;break;}
	printf("%I64d %d",max(0ll,n-m*2),n-ans);
}