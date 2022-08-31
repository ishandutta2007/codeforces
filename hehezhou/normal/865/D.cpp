#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	int n,w;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w);
		if(!q.empty()&&q.top()<w)ans+=w-q.top(),q.pop(),q.push(w);
		q.push(w);
	}
	return printf("%lld\n",ans),0;
}