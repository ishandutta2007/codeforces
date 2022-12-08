#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int main() {
	int n,a;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		a-=i;
		q.push(a);
		if(q.top()>a) {
			ans+=q.top()-a;
			q.pop();
			q.push(a);
		}
	}
	printf("%lld\n",ans);
	return 0;
}