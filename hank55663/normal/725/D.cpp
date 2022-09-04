#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	pair<long long int,long long int> p[300005];
	long long int w,t;
	scanf("%I64d %I64d",&t,&w);
	for(int i=0;i<n-1;i++)
	scanf("%I64d %I64d",&p[i].first,&p[i].second);
	sort(p,p+n-1);
	priority_queue<long long int,vector<long long int>,greater<long long int> > pq;
	int ans=1e9;
	for(int i=n-2;i>=0;i--){
		if(p[i].first<=t){
			while(!pq.empty()&&p[i].first<=t&&t>pq.top()){
				if(ans>pq.size())
				ans=pq.size();
				long long int a=pq.top();
				pq.pop();
				t-=a;
				t--;
			}
			if(p[i].first<=t&&ans>pq.size())
			ans=pq.size();
		}
		pq.push(p[i].second-p[i].first);
	}
	while(!pq.empty()&&t>pq.top()){
				long long int a=pq.top();
				pq.pop();
				t-=a;
				t--;
	}
	if(ans>pq.size())
	ans=pq.size();
	printf("%d\n",ans+1);
}