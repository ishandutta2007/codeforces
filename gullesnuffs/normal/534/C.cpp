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

long long d[500005];

int main(){
	long long n, A;
	scanf("%I64d%I64d", &n, &A);
	long long lo=0,hi=0;
	rep(i,0,n){
		scanf("%I64d",d+i);
		++lo;
		hi += d[i];
	}
	rep(i,0,n){
		int ans=0;
		long long num1=d[i]+lo-A-1;
		long long num2=A+d[i]-hi-1;
		if(num1 > 0)ans += num1;
		if(num2 > 0)ans += num2;
		printf("%d ", ans);
	}
	printf("\n");
}