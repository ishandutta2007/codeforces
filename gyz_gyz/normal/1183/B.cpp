#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
int a[N];
void sol(){int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);int ans=a[1]+k;
	rep(i,2,n)ans=min(ans,a[i]+k);
	rep(i,1,n)if(a[i]-ans>k){
		printf("-1\n");return;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}