#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
const ll inf=1e18;
vector<int>p[20];
vector<pii>res;
int main(){int n,nw=0,tot=0;
	scanf("%d",&n);
	dep(i,15,0)if((n>>i)&1){
		rep(j,0,i-1)rep(k,0,(1<<i)-1)if(!((k>>j)&1))
			res.push_back({nw+k+1,nw+(k^(1<<j))+1});
		++tot;
		rep(j,nw+1,nw+(1<<i))p[tot].push_back(j);
		nw+=1<<i;
	}
	while(tot>2){
		int s=p[tot].size();
		if(s==int(p[tot-1].size())){
			rep(i,0,s-1){
				res.push_back({p[tot-1][i],p[tot].back()});
				p[tot-1].push_back(p[tot].back());
				p[tot].pop_back();
			}
			--tot;
		}else{
			rep(i,0,s-1){
				res.push_back({p[tot][i],p[1].back()});
				p[tot].push_back(p[1].back());
				p[1].pop_back();
			}
		}
	}
	printf("%d\n",(int)res.size());
	for(auto&i:res)printf("%d %d\n",i.fr,i.sc);
}