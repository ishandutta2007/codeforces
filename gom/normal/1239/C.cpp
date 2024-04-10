#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7;
const int N=1e5+5;
int n;
ll tree[4*N];
ll t[N],ans[N],p,cur=0;
pll a[N];
queue<int> que;
priority_queue<int,vector<int>,greater<int>> pq;
priority_queue<ll,vector<ll>,greater<ll>> Events;
void upd(int nd,int l,int r,int x,ll v)
{
	if(l==r){
		tree[nd]=v;
		return;
	}
	int m=(l+r)/2;
	if(x<=m) upd(nd<<1,l,m,x,v);
	else upd(nd<<1|1,m+1,r,x,v);
	if(tree[nd<<1]&&tree[nd<<1|1]) tree[nd]=min(tree[nd<<1],tree[nd<<1|1]);
	else if(tree[nd<<1]) tree[nd]=tree[nd<<1];
	else tree[nd]=tree[nd<<1|1];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		a[i]={t[i],i};
	}
	sort(a+1,a+1+n);
	for(int cnt=0,i=1;cnt<n;){
		cur=1e18;
		if(Events.size()) cur=min(cur,Events.top());
		if(i<=n) cur=min(cur,a[i].fi);
		//cout<<i<<" "<<cur<<" "<<cnt<<endl;
		//cin>>t[100];
		if(Events.size()&&Events.top()==cur){
			Events.pop();
			int curH=que.front(); que.pop();
			upd(1,1,n,curH,0);
			cnt++;
			if(que.size()){
				ans[que.front()]=cur+p;
				Events.emplace(cur+p);
			}
		}
		while(i<=n&&a[i].fi==cur){ //one sitting person now waits
			pq.emplace(a[i].se);
			i++;
		}
		ll curMin=tree[1];
		if(pq.size()&&(curMin==0||pq.top()<curMin)){ //one waiting person goes to queue
			if(que.size()==0){
				ans[pq.top()]=cur+p;
				Events.emplace(cur+p);
			}
			//cout<<cur<<" : "<<pq.top()<<" go "<<curMin<<" "<<que.size()<<" "<<pq.size()<<endl;
			upd(1,1,n,pq.top(),pq.top());
			que.emplace(pq.top()); pq.pop();
		}
		
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}