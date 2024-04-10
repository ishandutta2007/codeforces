#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char adj[305][305];
int p[305];

int main(){
	int n;
	scanf("%d", &n);
	rep(i, 0, n){
		scanf("%d", p+i);
		--p[i];
	}
	rep(i, 0, n){
		scanf("%s", adj[i]);
		adj[i][i]='1';
	}
	rep(k, 0, n)
		rep(i, 0, n)
			rep(j, 0, n){
				if(adj[i][k]=='1' && adj[k][j]=='1')
					adj[i][j]='1';
			}
	rep(i, 0, n){
		int best=n+1;
		int bestP;
		rep(j, i, n){
			if(p[j] < best && adj[i][j] == '1'){
				best=p[j];
				bestP=j;
			}
		}
		swap(p[i], p[bestP]);
	}
	rep(i, 0, n)
		printf("%d ", p[i]+1);
	printf("\n");
}