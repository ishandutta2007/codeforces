#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
set<int>p[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].insert(y);
		p[y].insert(x);
	}
	queue<int>q;
	rep(i,1,n)if(p[i].size()==1)q.push(i);
	while(!q.empty()){
		if(q.size()==1){
			printf("! %d\n",q.front());
			fflush(stdout);return 0;
		}
		int x=q.front();q.pop();
		int y=q.front();q.pop();
		printf("? %d %d\n",x,y);fflush(stdout);
		int z;scanf("%d",&z);
		if(z==x||z==y){
			printf("! %d\n",z);
			fflush(stdout);return 0;
		}
		for(auto&i:p[x]){
			p[i].erase(x);
			if(p[i].size()==1)q.push(i);
		}
		for(auto&i:p[y]){
			p[i].erase(y);
			if(p[i].size()==1)q.push(i);
		}
	}
	
}