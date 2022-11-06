#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=1e6+10;
ll an1,an2,a[N];int tot;
void dfs(int x,ll y,ll z){
	if(x>tot){
		if(max(y,z)<max(an1,an2))an1=y,an2=z;
		return;
	}
	dfs(x+1,y*a[x],z);dfs(x+1,y,z*a[x]);
}
int main(){ll n;
	scanf("%lld",&n);an1=1;an2=n;
	rep(i,2,n){
		if(1ll*i*i>n)break;
		if(n%i)continue;
		a[++tot]=1;
		while(!(n%i))a[tot]*=i,n/=i;
	}
	if(n>1)a[++tot]=n;
	dfs(1,1,1);printf("%lld %lld\n",an1,an2);
}