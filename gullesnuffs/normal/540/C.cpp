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

char s[505][505];
int n, m;
bool vis[505][505];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

bool inside(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i,0,n){
		scanf("%s", s[i]);
	}
	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	--r1;--r2;--c1;--c2;
	queue<pair<int, int> > q;
	q.push(make_pair(r1, c1));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		if(vis[r][c])
			continue;
		vis[r][c]=1;
		rep(i,0,4){
			int nr=r+dx[i];
			int nc=c+dy[i];
			if(!inside(nr, nc))
				continue;
			if(s[nr][nc] == 'X' && (nr != r2 || nc != c2))
				continue;
			if(s[nr][nc] == 'X'){
				puts("YES");
				return 0;
			}
			q.push(make_pair(nr, nc));
		}
	}
	if(!vis[r2][c2]){
		puts("NO");
		return 0;
	}
	int num=0;
	rep(i,0,4){
		int nr=r2+dx[i];
		int nc=c2+dy[i];
		if(!inside(nr, nc))
			continue;
		if(s[nr][nc] == 'X' && (nr != r1 || nc != c1))
			continue;
		++num;
	}
	if(num < 2){
		puts("NO");
		return 0;
	}
	puts("YES");
}