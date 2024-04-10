#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int inf=1e9;
int a[N],nt[N],l[N],r[N];
vector<int>p[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&nt[i]);
	set<int>s;s.insert(n+1);
	rep(i,1,n){
		while(*s.begin()<=i)s.erase(s.begin());
		if(~nt[i]){
			if(*s.begin()<nt[i]){
				printf("-1\n");return;
			}
			s.insert(nt[i]);
		}else nt[i]=*s.begin();
	}
	rep(i,1,n+1)l[i]=r[i]=0,p[i].clear();
	rep(i,1,n)p[nt[i]].push_back(i);
	rep(i,1,n+1)if(!p[i].empty()){
		int sz=p[i].size();l[i]=p[i][0];
		rep(j,1,sz-1)r[p[i][j-1]]=p[i][j];
	}
	queue<int>q;q.push(n+1);int nw=n+1;
	while(!q.empty()){
		int x=q.front();q.pop();a[x]=nw--;
		if(l[x])q.push(l[x]);
		if(r[x])q.push(r[x]);
	}
	rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}