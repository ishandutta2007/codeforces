#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,m,a[20][N],b[20][N];ll ans,x;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)rep(j,1,n){
		scanf("%d",&a[i][j]);
		b[i][a[i][j]]=j;
	}
	rep(j,1,n){x++;
		rep(i,2,m)if(b[i][a[1][j]]!=b[i][a[1][j-1]]+1){
			x=1;break;
		}ans+=x;
	}
	printf("%lld\n",ans);
}