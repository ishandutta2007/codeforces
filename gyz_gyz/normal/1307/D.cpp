#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const int inf=1e9;
int d1[N],dn[N],sp[N];
vector<int>p[N];
bool cmp(int x,int y){
	return d1[x]-dn[x]<d1[y]-dn[y];
}
int main(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k)scanf("%d",&sp[i]);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	rep(i,1,n)d1[i]=dn[i]=inf;
	d1[1]=0;queue<int>q;q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto&i:p[x])if(d1[i]>d1[x]){
			d1[i]=d1[x]+1;q.push(i);
		}
	}
	dn[n]=0;q.push(n);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto&i:p[x])if(dn[i]>dn[x]){
			dn[i]=dn[x]+1;q.push(i);
		}
	}
	sort(sp+1,sp+k+1,cmp);
	int ans=0,md1=d1[sp[1]];
	rep(i,2,k){
		ans=max(ans,min(md1+dn[sp[i]]+1,d1[n]));
		md1=max(md1,d1[sp[i]]);
	}
	printf("%d\n",ans);
}