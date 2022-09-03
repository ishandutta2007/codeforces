#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
int mod=998244353;
int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	int a[100005];
	for(int i =1;i<=n;i++)
		scanf("%d",&a[i]);
	multiset<int> s;
	LL sum=0;
	LL dp[100005];
	dp[0]=0;
	for(int i = 1;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
		s.insert(a[i]);
		sum+=a[i];
		if(s.size()>=c){
			dp[i]=min(sum-*s.begin()+dp[i-c],dp[i]);
			s.erase(s.find(a[i-c+1]));
			sum-=a[i-c+1];
		}
	}
	printf("%lld\n",dp[n]);

}