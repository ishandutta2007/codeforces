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

int n, q;
int p[200005], l[200005];
int cost[200005][20];
int pos[200005][20];
int rightMax[200005][20];
int rightMaxPos[200005][20];

int getHighest(int l, int r){
	int ret=0;
	for(int i=19; i >= 0; --i){
		if(l+(1<<i) <= r){
			ret=max(rightMax[l][i], ret);
			l += (1<<i);
		}
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	rep(i, 0, n){
		scanf("%d%d", p+i, l+i);
		rightMax[i][0]=p[i]+l[i];
		rightMaxPos[i][0]=i;
	}
	for(int j=1; j < 20; ++j)
		for(int i=0; i+(1<<j) <= n; ++i){
			rightMax[i][j]=max(rightMax[i][j-1], rightMax[i+(1<<(j-1))][j-1]);
			if(rightMax[i][j-1] > rightMax[i+(1<<(j-1))][j-1]){
				rightMaxPos[i][j]=rightMaxPos[i][j-1];
			}
			else{
				rightMaxPos[i][j]=rightMaxPos[i+(1<<(j-1))][j-1];
			}
		}
	for(int j=0; j < 20; ++j){
	pos[n][j]=n;
	cost[n][j]=0;
	}
	p[n]=2010000000;
	for(int i=n-1; i >= 0; --i){
		int x;
		x=i+1;
		while(p[i]+l[i] >= p[pos[x][0]]){
			x=pos[x][0];
			if(x == n)
				break;
		}
		if(p[i]+l[i] >= p[x]){
			int c=p[pos[x][0]]-getHighest(i, pos[x][0]);
			pos[i][0]=pos[x][0];
			cost[i][0]=c;
		}
		else{
			pos[i][0]=i+1;
			cost[i][0]=p[i+1]-p[i]-l[i];
		}
	}
	for(int j=1; j < 20; ++j)
		for(int i=0; i < n; ++i){
			pos[i][j]=pos[pos[i][j-1]][j-1];
			cost[i][j]=cost[i][j-1]+cost[pos[i][j-1]][j-1];
		}
	scanf("%d", &q);
	rep(i, 0, q){
		int x, y;
		scanf("%d%d", &x, &y);
		--x;--y;
		int ans=0;
		for(int i=19; i >= 0; --i){
			if(pos[x][i] <= y){
				ans += cost[x][i];
				x=pos[x][i];
			}
		}
		printf("%d\n", ans);
	}
	/*for(int j=1; j < 20; ++j)
		for(int i=0; i < n; ++i){
			if(j == 0){
				if(i < n-1)
					cost[i][j]=max(0, p[i+1]-p[i]-l[i]);
				continue;
			}
			int r=rightMaxPos[i][j];
			if(rightMax[i][j] > rightMax[i][0]){
				pos[i][j]=pos[r][j];
				cost[i][j]=cost[r][j];
			}
			else{
				
			}
		}*/
}