#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
int a[N],b[N];bool v[N];
void sol(){
	int n,tot=0;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		ans+=a[i];v[i]=0;
	}
	rep(i,1,n*2-2){int x;
		scanf("%d",&x);
		if(v[x])b[++tot]=a[x];else v[x]=1;
	}
	sort(b+1,b+tot+1);
	dep(i,tot,0){
		printf("%lld%c",ans,i?' ':'\n');
		ans+=b[i];
	}
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}