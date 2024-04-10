#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int n,m,d[200005],id[200005],bad[200005];
ll a[200005];
vector<ll> sum[200005];
struct Heap{
	priority_queue<ll> q,del;
	void push(ll x){
		q.push(x);
	}
	void pop(ll x){
		del.push(x);
	}
	ll top(){
		while(q.size()&&del.size()&&q.top()==del.top())q.pop(),del.pop();
		return q.top();
	}
	void clear(){
		while(q.size())q.pop();
		while(del.size())del.pop();
	}
}q;
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	int ts=0;
	for(int i=1;i<n;i++){
		if(n%i)continue;
		d[++ts]=i;
	}
	for(int i=1;i<=ts;i++){
		for(int j=i+1;j<=ts;j++){
			if(d[j]%d[i]==0)bad[i]=1;
		}
	}
	for(int i=1;i<=ts;i++){
		if(bad[i])continue;
		sum[i].resize(d[i]);
		for(int j=0;j<d[i];j++){
			for(int k=j;k<n;k+=d[i]){
				sum[i][j]+=a[k];
			}
			q.push(sum[i][j]*d[i]);
		}
	}
	cout<<q.top()<<'\n';
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y),x--;
		for(int j=1;j<=ts;j++){
			if(bad[j])continue;
			q.pop(sum[j][x%d[j]]*d[j]);
			sum[j][x%d[j]]+=y-a[x];
			q.push(sum[j][x%d[j]]*d[j]);
		}
		a[x]=y;
		cout<<q.top()<<'\n';
	}
	q.clear();
	for(int i=1;i<=n;i++){
		d[i]=id[i]=bad[i]=a[i]=0;
		sum[i].clear();
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}