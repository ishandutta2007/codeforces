#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const int N=1e6+5;
const ll mod=1e9+7;
ll n,w,m,a[N],res[N];
void add(int l,int r,ll v)
{
	res[l]+=v;
	res[r+1]-=v;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>m>>w;
	for(int i=1;i<=m;i++){
		cin>>n; for(int i=1;i<=n;i++) cin>>a[i];
		int s=n,e=w-n+1;
		if(s<e){
			ll cur=0;
			for(int i=1;i<s;i++){
				cur=max(cur,a[i]);
				add(i,i,cur);
			}
			cur=max(cur,a[s]);
			add(s,e,cur);
			cur=0;
			for(int i=w;i>e;i--){
				cur=max(cur,a[n+i-w]);
				add(i,i,cur);
			}
			continue;
		}
		int d=w-n;
		swap(s,e);
		ll cur=0;
		for(int i=1;i<s;i++){
			cur=max(cur,a[i]);
			add(i,i,cur);
		}
		cur=0;
		for(int i=w;i>e;i--){
			cur=max(cur,a[n+i-w]);
			add(i,i,cur);
		}
		deque<int> dq;
		for(int i=1;i<=e;i++){
			while(dq.size()&&i-dq.front()>d) dq.pop_front();
			while(dq.size()&&a[dq.back()]<=a[i]) dq.pop_back();
			dq.push_back(i);
			if(i>=s) add(i,i,a[dq.front()]);
		}
	}
	for(int i=1;i<=w;i++){
		res[i]+=res[i-1];
		cout<<res[i]<<" ";
	}
    return 0;
}