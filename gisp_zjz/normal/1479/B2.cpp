#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+100;
const int M=998244353;
int w,a[maxn],b[maxn],n,m,dp[maxn],last[maxn];
vector<int> p;

int main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++){
		if (a[i]==a[i-1]) continue;
		b[++m]=a[i];
	}
	b[0]=-1; b[m+1]=-2;
	for (int i=1;i<=m;i++){
		dp[i]=dp[i-1];
		int j=last[b[i]];
		if (j){
			dp[i]=max(dp[i],dp[j+1]+1);
		}
		last[b[i]]=i;
	}
	cout << m-dp[m] << endl;
	return 0;
}