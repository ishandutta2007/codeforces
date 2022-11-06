#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const ll inf=1e18;
const int mo=998244353;
int c[N],f[N];
vector<int>res[N];
int main(){int n,k;multiset<int>s;
	scanf("%d%d",&n,&k);
	rep(i,1,n){int x;
		scanf("%d",&x);
		s.insert(x);
	}int ls=0;
	rep(i,1,k){
		scanf("%d",&c[i]);
		if(i==1||c[i]!=c[i-1])ls=i-1;
		f[i]=ls;
	}
	int ans=1,nw=k,tot=0;
	while(!s.empty()){
		auto p=s.upper_bound(nw);
		if(p==s.begin()){
			++ans;nw=k;tot=0;continue;
		}
		--p;++tot;nw=*p;
		if(tot==c[*p])nw=f[*p];
		res[ans].push_back(*p);s.erase(p);
	}
	printf("%d\n",ans);
	rep(i,1,ans){
		printf("%d",(int)res[i].size());
		for(auto&j:res[i])printf(" %d",j);
		printf("\n");
	}
}