#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,m,tot,x,ans,a[N];
int main(){
	scanf("%d%d",&n,&m);m--;
	rep(i,1,n){
		scanf("%d",&x);
		if(x)a[++tot]=i;
	}
	sort(a+1,a+tot+1);a[0]=-m;a[tot+1]=n+m+1;x=0;
	rep(i,1,tot+1)if(a[i]-a[i-1]-1>m*2){
		printf("-1");return 0;
	}
	rep(i,1,tot)if(a[i+1]-a[x]-1>m*2)ans++,x=i;
	printf("%d",ans);
}