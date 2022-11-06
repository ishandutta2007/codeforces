#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int inf=1e9;
const int mo=998244353;
int a[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)a[i]=n;
	rep(i,1,n){int x;
		scanf("%d",&x);x=min(x,n);
		dep(i,n,1)a[i-1]=min(a[i-1],a[i]);
		rep(i,x+1,n)a[i]=n;
		rep(i,0,x-1){
			a[i+1]=min(a[i+1],a[i]+1);++a[i];
		}
	}int ans=n;
	rep(i,0,n)ans=min(ans,a[i]);
	printf("%d\n",ans);
}