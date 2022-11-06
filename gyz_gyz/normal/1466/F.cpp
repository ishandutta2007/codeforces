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
const ll inf=1e18;
int f[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,m)f[i]=i;
	vector<int>res;int ans=1;
	rep(i,1,n){int k,x,y;
		scanf("%d%d",&k,&x);
		if(k==2)scanf("%d",&y);else y=m+1;
		x=gf(x);y=gf(y);
		if(x!=y){
			f[x]=y;ans=ans*2%mo;res.push_back(i);
		}
	}
	printf("%d %d\n",ans,int(res.size()));
	for(auto&i:res)printf("%d ",i);printf("\n");
}