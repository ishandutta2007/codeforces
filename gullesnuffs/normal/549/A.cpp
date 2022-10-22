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

char a[55][55];
int has[256];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,n)
		scanf("%s", a[i]);
	int ans=0;
	rep(i,0,n-1)
		rep(j,0,m-1){
			has['f']=0;
			has['a']=0;
			has['c']=0;
			has['e']=0;
			rep(k,0,2)
				rep(l,0,2)
					has[a[i+k][j+l]]++;
			if(has['f'] && has['a'] && has['c'] && has['e'])
				++ans;
		}
	printf("%d\n", ans);
}