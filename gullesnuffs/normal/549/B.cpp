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

char con[105][105];
bool used[105];
int need[105];

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%s", con[i]);
	}
	rep(i,0,n)
		scanf("%d", need+i);
	int ans=0;
	while(true){
		bool ok=1;
		rep(i,0,n){
			if(need[i] != 0)
				continue;
			used[i]=1;
			ok=0;
			++ans;
			rep(j,0,n){
				if(con[i][j] == '0')
					continue;
				--need[j];
			}
		}
		if(ok){
			printf("%d\n", ans);
			rep(i,0,n){
				if(!used[i])continue;
				printf("%d ", i+1);
			}
			printf("\n");
			return 0;
		}
	}
}