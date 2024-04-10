#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
char s[N],v[N];
void sol(){int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	multiset<int>v;int x=0;
	rep(i,1,n){
		v.insert(x);x+=(s[i]=='0'?1:-1);
	}int ans=0;
	if(!x)return(void)printf("%d\n",v.count(m)?-1:0);
	for(auto&i:v)if((m-i)/x>=0&&!((m-i)%x))++ans;
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}