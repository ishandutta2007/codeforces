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

bool used[2000];
int w[2000];
int need[2000];

int main(){
	int m, t, r;
	scanf("%d%d%d", &m, &t, &r);
	rep(i,0,m){
		scanf("%d", w+i);
		need[w[i]+500]=r;
	}
	int ans=0;
	while(true){
		bool ok=1;
		for(int i=0; i < 2000; ++i){
			if(need[i] <= 0)
				continue;
			++ans;
			ok=0;
			for(int j=i; j >= 0; --j){
				if(!used[j]){
					used[j]=1;
					for(int k=0; k < t; ++k){
						--need[j+k];
					}
					break;
				}
				if(j == 0){
					printf("-1\n");
					return 0;
				}
			}
			break;
		}
		if(ok)
			break;
	}
	printf("%d\n", ans);
}