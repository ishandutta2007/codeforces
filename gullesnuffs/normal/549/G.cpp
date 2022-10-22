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

int a[200005];
int b[200005];

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
		b[i]=a[i]+i;
	}
	sort(b,b+n);
	bool ok=1;
	rep(i,0,n-1)
		if(b[i]==b[i+1])
			ok=0;
	if(!ok){
		puts(":(");
		return 0;
	}
	rep(i,0,n)
		printf("%d ", b[i]-i);
	printf("\n");
}