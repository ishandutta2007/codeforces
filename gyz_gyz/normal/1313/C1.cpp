#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
const int inf=1e9;
int a[N],b[N],res[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	ll ans=0;
	rep(i,1,n){
		b[i]=a[i];ll tot=0;
		dep(j,i-1,1)b[j]=min(a[j],b[j+1]);
		rep(j,i+1,n)b[j]=min(a[j],b[j-1]);
		rep(j,1,n)tot+=b[j];
		if(tot>ans){ans=tot;
			rep(j,1,n)res[j]=b[j];
		}
	}
	rep(i,1,n)printf("%d%c",res[i],i==n?'\n':' ');
}