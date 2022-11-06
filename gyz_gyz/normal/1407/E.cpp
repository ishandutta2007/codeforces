#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int mo=998244353;
const int inf=1e9;
int d[2][N];vector<pii>p[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		p[y].push_back({x,z});
	}
	queue<int>q;q.push(n);
	rep(i,1,n-1)d[0][i]=d[1][i]=inf;
	for(;!q.empty();q.pop()){
		int x=q.front(),y=max(d[0][x],d[1][x])+1;
		for(auto&i:p[x])if(d[i.sc][i.fr]==inf){
			d[i.sc][i.fr]=y;
			if(d[i.sc][i.fr]!=inf&&d[i.sc^1][i.fr]!=inf)q.push(i.fr);
		}
	}
	printf("%d\n",max(d[0][1],d[1][1])==inf?-1:max(d[0][1],d[1][1]));
	rep(i,1,n)printf("%d",int(d[0][i]<d[1][i]));
}