#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n,a[200005];
void Solve(){
	scanf("%d",&n);
	deque<int> q;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(!q.size())q.push_back(a[i]);
		else if(a[i]<q.front())q.push_front(a[i]);
		else q.push_back(a[i]);
	}
	for(int i:q)cout<<i<<' ';
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}