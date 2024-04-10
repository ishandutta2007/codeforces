#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int a[100005];
ll sumDistance2[100005];
int maxA[500005][20];
int maxPos[500005][20];

int getMax(int l, int r){
	int ans;
	int val=-1;
	rrep(i,20,0){
		if(l+(1<<i) <= r){
			if(maxA[l][i] > val){
				val=maxA[l][i];
				ans=maxPos[l][i];
			}
			l += (1<<i);
		}
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	ll ans=0;
	rep(i,0,n-1){
		scanf("%d", a+i);
		maxA[i][0]=a[i];
		maxPos[i][0]=i;
	}
	rep(i,1,17){
		rep(j,0,n){
			maxA[j][i]=max(maxA[j][i-1], maxA[j+(1<<(i-1))][i-1]);
			if(maxA[j][i-1] > maxA[j+(1<<(i-1))][i-1]){
				maxPos[j][i]=maxPos[j][i-1];
			}
			else
				maxPos[j][i]=maxPos[j+(1<<(i-1))][i-1];
		}
	}
	rrep(i,n-1,0){
		// Distance 1
		ans += a[i]-i-1;
		if(a[i] == n)
			continue;
		int b=getMax(i, a[i]);
		// Distance at least 3
		sumDistance2[i]=sumDistance2[b]+n-a[b];
		// Distance 2
		sumDistance2[i] += 2*(a[b]-a[i]);
		ans += sumDistance2[i];
	}
	printf("%I64d\n", ans);
}