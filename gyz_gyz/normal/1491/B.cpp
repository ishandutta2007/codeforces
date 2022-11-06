#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int mo=1e9+7;
const ll inf=1e9;
void sol(){int n,u,v,ls;bool ok=0,eq=1;
	scanf("%d%d%d%d",&n,&u,&v,&ls);
	rep(i,2,n){int x;
		scanf("%d",&x);
		if(abs(x-ls)>1)ok=1;
		if(x!=ls)eq=0;
		ls=x;
	}
	if(ok)printf("0\n");
	else if(eq)printf("%d\n",v+min(u,v));
	else printf("%d\n",min(u,v));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}