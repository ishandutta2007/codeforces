#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define N 131072
#define ll long long
#define mo 1000000007
#define inf 1000000000
using namespace std;
int n,k,x,y;ll ans;
map<int,int>p;
int main(){
	scanf("%d%d",&n,&k);
	ans=1ll*n*(n+1)/2;p[0]=1;
	rep(i,1,n){
		scanf("%d",&y);x^=y;
		x=min(x,(1<<k)-x-1);
		ans-=p[x]/2;p[x]++;
	}
	printf("%I64d",ans);
}