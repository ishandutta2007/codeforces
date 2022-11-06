#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 200000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,m,k,ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k){
		ans+=(n+m-2)*2;
		n-=4;m-=4;
	}
	printf("%d\n",ans);
}