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

int n, m;
char s[105][105];
ll val[105][105];
ll target[105][105];

int main(){
	scanf("%d%d", &n, &m);
	rep(i,0,n){
		scanf("%s", s[i]);
		rep(j,0,m){
			if(s[i][j] == 'W')
				target[i][j]=1;
			else
				target[i][j]=-1;
		}
	}
	int ans=0;
	rrep(i,n,0)
		rrep(j,m,0){
			if(target[i][j] == val[i][j])
				continue;
			ll add=target[i][j]-val[i][j];
			++ans;
			rep(k,0,i+1)
				rep(l,0,j+1){
					val[k][l] += add;
				}
		}
	printf("%d\n", ans);
}