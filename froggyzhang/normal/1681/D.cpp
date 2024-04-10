#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int> dis;
int n;
ll X;
vector<int> Get(ll x){
	vector<int> A;
	while(x)A.push_back(x%10),x/=10;
	return A;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>X;
	dis[X]=0;
	queue<ll> q;
	q.push(X);
	while(!q.empty()){
		ll u=q.front();
		int d=dis[u];
		q.pop();
		auto A=Get(u);
		if(A.size()>=n){
			cout<<d<<'\n';
			return 0;
		}
		for(auto t:A){
			ll v=u*t;
			if(!dis.count(v)){
				dis[v]=d+1;
				q.push(v);
			}
		}
	}
	cout<<-1<<'\n';
	return 0;
}