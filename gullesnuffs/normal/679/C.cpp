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

char f[505][505];
int region[505][505];
int regionSize[505000];
int regionN;
int n, k;
int hasRegion[500000];
int totSize;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

void rec(int i, int j){
	rep(k,0,4){
		int x=i+dx[k];
		int y=j+dy[k];
		if(x < 0 || y < 0 || x >= n || y >= n || f[x][y] == 'X' || region[x][y])
			continue;
		++regionSize[region[i][j]];
		region[x][y]=region[i][j];
		rec(x, y);
	}
}

void addSquare(int x, int y){
	if(f[x][y] == 'X'){
		return;
	}
	int r=region[x][y];
	if(!hasRegion[r]){
		totSize += regionSize[r];
	}
	++hasRegion[r];
}

void removeSquare(int x, int y){
	if(f[x][y] == 'X'){
		return;
	}
	int r=region[x][y];
	--hasRegion[r];
	if(!hasRegion[r]){
		totSize -= regionSize[r];
	}
}

int main(){
	scanf("%d%d", &n, &k);
	rep(i,0,n)
		scanf("%s", f[i]);
	rep(i,0,n)
	rep(j,0,n){
		if(f[i][j] == 'X' || region[i][j])
			continue;
		region[i][j]=++regionN;
		++regionSize[region[i][j]];
		rec(i,j);
	}
	int ans=0;
	rep(sx,0,n-k+1){
		rep(j,0,regionN+1)
			hasRegion[j]=0;
		totSize=0;
		rep(x,sx,sx+k){
		rep(y,0,k){
			addSquare(x, y);
		}
		}
		if(sx+k < n)
		rep(y,0,k){
			addSquare(sx+k, y);
		}
		if(sx-1 >= 0)
		rep(y,0,k){
			addSquare(sx-1, y);
		}
		if(k < n)
			rep(x,sx,sx+k)
				addSquare(x, k);
		rep(x,sx,sx+k)
		rep(y,0,k)
			if(f[x][y] == 'X')
				++totSize;
		ans=max(ans, totSize);
		rep(sy,1,n-k+1){
			if(sy > 1){
				rep(x,sx,sx+k)
					removeSquare(x, sy-2);
			}
			rep(x,sx,sx+k){
				if(f[x][sy-1] == 'X')
					--totSize;
				if(f[x][sy+k-1] == 'X')
					++totSize;
			}
			if(sy+k < n)
				rep(x,sx,sx+k)
					addSquare(x, sy+k);
			if(sx){
				addSquare(sx-1, sy+k-1);
				removeSquare(sx-1, sy-1);
			}
			if(sx+k < n){
				addSquare(sx+k, sy+k-1);
				removeSquare(sx+k, sy-1);
			}
			ans=max(ans, totSize);
		}
	}
	printf("%d\n", ans);
}