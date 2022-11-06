#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
vector<int>p[N];int v[N];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		p[i].clear();v[i]=0;
	}
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	queue<int>q1,q2;v[1]=1;q1.push(1);
	while(!q1.empty()){
		int x=q1.front();q1.pop();
		if(v[x]>1)continue;
		v[x]=3;
		for(auto&i:p[x])if(v[i]<2){
			v[i]=2;q2.push(i);
		}
		while(!q2.empty()){
			int y=q2.front();q2.pop();
			if(v[y]>2)continue;
			for(auto&i:p[y])if(!v[i]){
				v[i]=1;q1.push(i);
			}
		}
	}
	int cnt=0;
	rep(i,1,n)if(v[i]==3)++cnt;
	else if(v[i]<2){
		printf("NO\n");return;
	}
	printf("YES\n%d\n",cnt);
	rep(i,1,n)if(v[i]==3)printf("%d ",i);
	printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}