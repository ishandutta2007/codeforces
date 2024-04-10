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

int main(){
	int v1, v2;
	int t, d;
	scanf("%d%d%d%d", &v1, &v2, &t, &d);
	--t;
	int ans=0;
	for(int j=0; j <= t; ++j){
	for(int D=-d; D <= d; ++D){
		int len=v1;
		int v=v1;
		for(int i=0; i < t; ++i){
			if(i < j)
				v += d;
			else if(i == j)
				v += D;
			else
				v -= d;
			len += v;
		}
		if(v == v2){
			ans=max(ans,len);
		}
	}
	}
	printf("%d\n", ans);
}