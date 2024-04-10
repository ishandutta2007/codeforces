#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n,a[200005];
void Solve(){
	scanf("%d",&n);
	int s=0,mx=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i],mx=max(mx,a[i]);
	cout<<min(s/2,s-mx)<<'\n';
	priority_queue<pr> q;
	for(int i=1;i<=n;i++)if(a[i])q.push(pr(a[i],i));
	while(q.size()>1){
		pr x=q.top();q.pop();
		pr y=q.top();q.pop();
		cout<<x.second<<' '<<y.second<<'\n';
		x.first--,y.first--;
		if(x.first)q.push(x);
		if(y.first)q.push(y);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}