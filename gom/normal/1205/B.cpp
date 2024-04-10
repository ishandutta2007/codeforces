#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll,ll> P;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
const int N=2e5+5,M=70;
const ll mod=1e9+7;
ll n,a[N],ans=1e18,d[N];
ll cnt[M];
vector<int> v[M],g[N];
vector<P> e;
void Do(int s,int e)
{
	for(int i=1;i<=n;i++) d[i]=1e18;
	d[s]=0;
	queue<int> que;
	que.push(s);
	while(que.size()){
		int x=que.front(); que.pop();
		for(auto &it : g[x]){
			int y=it;
			if(x==s&&y==e) continue;
			if(d[y]!=1e18) continue;
			d[y]=d[x]+1;
			que.push(y);
		}
	}
	ans=min(ans,d[e]+1LL);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(ll bit=0;bit<60;bit++){
			if(a[i]&(1LL<<bit)){
				cnt[bit]++;
				if(cnt[bit]>=3) ans=3;
				v[bit].push_back(i);
			}
		}
	}
	if(ans==3){
		cout<<ans;
		return 0;
	}
	for(int bit=0;bit<60;bit++){
		if(v[bit].size()<=1) continue;
		g[v[bit][0]].push_back(v[bit][1]);
		g[v[bit][1]].push_back(v[bit][0]);
		e.push_back(P(v[bit][0],v[bit][1]));
	}
	for(auto &it : e) Do(it.fi,it.se);
	if(ans==1e18) ans=-1;
	cout<<ans;
    return 0;
}