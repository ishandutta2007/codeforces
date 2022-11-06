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
vector<int>p[N];int a[N],t[N],d[N];
int main(){int n,m;queue<int>q;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int k;
		scanf("%d",&k);
		d[i]=d[i+n]=k;
		rep(j,1,k){int x;
			scanf("%d",&x);
			p[x+n].push_back(i);
			p[x].push_back(i+n);
		}
		if(!k){
			a[i]=-1;q.push(i);
			a[i+n]=1;q.push(i+n);
		}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		if(a[x]==1)for(auto&i:p[x])if(!a[i]){
			t[i]=x;a[i]=1;q.push(i);
		}
		if(a[x]==-1)for(auto&i:p[x])if(!--d[i]){
			a[i]=-1;q.push(i);
		}
	}int s;
	scanf("%d",&s);
	if(a[s]==1){
		printf("Win\n");
		for(int x=s;x;x=t[x])
			printf("%d%c",(x-1)%n+1,t[x]?' ':'\n');
	}else printf("%s\n",a[s]?"Lose":"Draw");
}