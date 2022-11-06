#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int n,a[N];
priority_queue<int> q;
int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long x=0;
	int ans=n;
	for(int i=1;i<=n;++i){
		x+=a[i];
		if(a[i]>=0)continue;
		q.push(-a[i]);
		while(x<0){
			--ans;
			x+=q.top();
			q.pop();
		}
	}
	cout<<ans<<endl;
}