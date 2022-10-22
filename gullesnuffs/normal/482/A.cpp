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
	int n, k;
	scanf("%d%d", &n, &k);
	int pre=1;
	int t=n, l=2;
	printf("1 ");
	for(int i=1; i < n; ++i){
		if(k > 2 || (k == 2 && pre > t)){
			if(pre < t){
				pre=t;
				--t;
				--k;
			}
			else{
				pre=l;
				++l;
				--k;
			}
		}
		else{
			if(k == 2){
				printf("%d %d ", l+1, l);
				k -= 2;
				pre=l+1;
				l += 2;
				++i;
				continue;
			}
			else{
				printf("%d ", l);
				++l;
				continue;
			}
		}
		printf("%d ", pre);
	}
}