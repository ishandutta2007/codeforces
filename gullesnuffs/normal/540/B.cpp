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

int a[1005];
int b[1005];

int main(){
	int n, k, p, x, y;
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	--y;
	x -= n;
	rep(i,0,k){
		scanf("%d", a+i);
		--a[i];
		x -= a[i];
	}
	if(x < 0){
		puts("-1");
		return 0;
	}
	sort(a, a+k);
	rep(i,k,n){
		a[i]=min(y, x);
		x -= a[i];
	}
	rep(i,0,n)
		b[i]=a[i];
	sort(b, b+n);
	int median=b[(n-1)/2]+b[n/2];
	if(median < 2*y){
		puts("-1");
		return 0;
	}
	rep(i,k,n)
		printf("%d ", a[i]+1);
	printf("\n");
}