#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
const ll inf=(1ll<<32)-1;
int a[N];
void sol(){int n,k;
	scanf("%d%d",&n,&k);
	int ans,s=2e9;
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(i>k&&a[i]-a[i-k]<s){
			s=a[i]-a[i-k];ans=(a[i]+a[i-k])/2;
		}
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}