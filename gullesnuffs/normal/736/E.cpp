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

int score[3005];
vector<int> hasScore[6005];
char ans[3005][3005];

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	int scoreLeft=(m*(m-1));
	rep(i,0,n){
		scanf("%d", score+i);
		hasScore[score[i]].push_back(i);
		scoreLeft -= score[i];
	}
	if(n == m){
		if(scoreLeft){
			puts("no");
			return 0;
		}
	}
	else{
		int average=scoreLeft/(m-n);
		int numLarger=scoreLeft%(m-n);
		int largestNew=average+(numLarger > 0);
		if(largestNew > score[n-1]){
			puts("no");
			return 0;
		}
		int j=n;
		rep(i,0,numLarger)
			hasScore[average+1].push_back(j++);
		while(j < m)
			hasScore[average].push_back(j++);
	}
	rep(i,0,m){
		ans[i][i]='X';
		ans[i][m]=0;
		for(int j=6000; j >= 0; --j){
			if(hasScore[j].empty())
				continue;
			int cur=hasScore[j].back();
			hasScore[j].pop_back();
			int opponents=m-i-1;
			int numWins=j-opponents;
			if(numWins < 0 || numWins > opponents){
				puts("no");
				return 0;
			}
			rep(k,0,j+1){
				vector<int> newV;
				while(!hasScore[k].empty()){
					int b=hasScore[k].back();
					hasScore[k].pop_back();
					if(numWins){
						ans[cur][b]='W';
						ans[b][cur]='L';
						newV.push_back(b);
						--numWins;
					}
					else{
						ans[cur][b]='D';
						ans[b][cur]='D';
						hasScore[k-1].push_back(b);
					}
				}
				hasScore[k]=newV;
			}
			break;
		}
	}
	printf("yes\n");
	rep(i,0,m)
		printf("%s\n", ans[i]);
}