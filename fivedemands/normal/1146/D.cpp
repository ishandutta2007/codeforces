#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pli;
#define fi first
#define se second
bool vis[300001];
int dis[300001];
ll m,g,n;
int a,b;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll sum(ll l,ll r){
	return (r+l)*(r-l+1)/2;
}
priority_queue<pli,vector<pli>,greater<pli> >pq;
ll ans=0;
ll cal(ll m){
	ll res=0;
	if(m>=3*max(a,b)){
		res+=sum(3*max(a,b)+2,m+1);
		m=3*max(a,b);
	}
	ans*=g;
	for(int i=1; i<=m ;i++) dis[i]=m+1,vis[i]=false;
	vis[0]=false;
	pq.push({0,0});
	while(!pq.empty()){
		int cur=pq.top().se;pq.pop();
		if(vis[cur]) continue;
		vis[cur]=true;
		if(cur+a<=m && dis[cur+a]>max(cur+a,dis[cur])){
			dis[cur+a]=max(cur+a,dis[cur]);
			pq.push({dis[cur+a],cur+a});
		}
		if(cur-b>=0 && dis[cur-b]>max(cur-b,dis[cur])){
			dis[cur-b]=max(cur-b,dis[cur]);
			pq.push({dis[cur-b],cur-b});
		}
	}
	for(int i=0; i<=m ;i++) res+=m-dis[i]+1;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> m >> a >> b;
	g=gcd(a,b);
	n=m%g;
	m/=g;a/=g;b/=g;
	ll num1=0;
	if(m!=0) num1=cal(m-1);
	ll num2=cal(m);
	cout << num1*g+(num2-num1)*(n+1) << endl;
}