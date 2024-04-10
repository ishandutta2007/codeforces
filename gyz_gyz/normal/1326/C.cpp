#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
const int mo=998244353;
int main(){
	int n,m,ls=0;ll tot=0,ans=1;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x>n-m){
			if(ls)ans=ans*(i-ls)%mo;
			ls=i;tot+=x;
		}
	}
	printf("%lld %lld\n",tot,ans);
}