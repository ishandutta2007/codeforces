#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
int p2[31];
int main(){
	p2[0]=1;int n;ll ans=0;map<int,int>p;
	rep(i,1,30)p2[i]=p2[i-1]*2;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		rep(j,0,30)if(x==p2[j])--ans;
		++p[x];
	}
	for(auto i:p)
		rep(j,0,30)if(p.count(p2[j]-i.fr))ans+=1ll*i.sc*p[p2[j]-i.fr];
	printf("%lld\n",ans/2);
}