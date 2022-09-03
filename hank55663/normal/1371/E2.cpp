#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
queue<int> q[100005];
int main() {
	int n,p;
	scanf("%d %d",&n,&p);
	int a[100005];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int Min=0;
	for(int i = 0;i<n;i++){
		Min=max(Min,a[i]-i);
	}
	vector<int> v;

	for(int i = Min;i<=Min+n;i++){
		q[i%p].push(i);
	}
	for(int i = n-1;i>=0;i--){
		v.pb(Min-(a[i]-i)+1);
	}
	int Max=2e9;
	for(int i = 0;i<n;i++){
		if((n-i)%p==0){
			Max=min(Max,n-i-v[i]+Min-1);
		}
		int val=((p-v[i]%p)%p+Min)%p;
		while(q[val].size()&&q[val].front()<=Min+n-i-v[i])q[val].pop();
	}
	vector<int> ans;
	for(int i = 0;i<p;i++){
		while(q[i].size()){
			if(q[i].front()<=Max)ans.pb(q[i].front());
			q[i].pop();
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto it:ans){
		printf("%d ",it);
	}
	printf("\n");
	return 0;
}