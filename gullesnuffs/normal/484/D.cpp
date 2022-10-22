#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n;
int a[1000005];
long long dp[1000005];
int ex[1000005];
int main(){
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
	}
	rep(i,1,n-1){
		if(a[i] >= a[i-1] && a[i] >= a[i+1])
			ex[i]=1;
		if(a[i] <= a[i-1] && a[i] <= a[i+1])
			ex[i]=1;
	}
	ex[0]=1;
	ex[n]=1;
	long long ans=0;
	rep(i,0,n){
		if(ex[i] || ex[i+1] || ex[i+2] || (i && ex[i-1])){
			int Min=1000000005, Max=-1000000005;
			int num=0;
			for(int j=i; j >= 0 && num <= 9; --j){
				Min=min(Min,a[j]);
				Max=max(Max,a[j]);
				if(j && ex[j-1])
					++num;
				dp[i+1]=max(dp[i+1], dp[j]+Max-Min);
				ans=max(ans,dp[i+1]);
			}
		}
	}
	printf("%I64d\n", ans);
}