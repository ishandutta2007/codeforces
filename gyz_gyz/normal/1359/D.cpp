#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
int a[N];
int main(){int n,ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(s,-30,30){int nw=0;
		rep(i,1,n)if(a[i]<=s){
			nw+=a[i];
			ans=max(ans,nw-s);
			if(nw<0)nw=0;
		}else nw=0;
	}
	printf("%d\n",ans);
}