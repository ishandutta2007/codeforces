#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int n;
priority_queue<ll,vector<ll>,greater<ll> >pq;
ll sum=0;
ll v[100001],t[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> v[i];
	for(int i=1; i<=n ;i++){
		cin >> t[i];
		pq.push(v[i]+sum);
		sum+=t[i];
		ll ans=0;
		while(!pq.empty() && pq.top()<=sum){
			ans+=pq.top()+t[i]-sum;
			pq.pop();
		}
		ans+=t[i]*pq.size();
		cout << ans << ' ';
	}
}