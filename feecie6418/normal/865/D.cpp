#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n;
priority_queue<pr> q;
ll ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(q.size()&&q.top().first+x>0){
			pr y=q.top();
			ans+=x+y.first;
			q.pop();
			if(y.second)y.second=0,q.push(y);
			q.push(pr(-x,1));
		}
		else q.push(pr(-x,0));
	}
	cout<<ans;
}