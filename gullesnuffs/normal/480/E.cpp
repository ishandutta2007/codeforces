#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char field[2005][2005];
int dp[2005][2005];
int cnt[2005];

/*void rec(int a, int b){
	if(a && b && dp[a-1][b-1] > dp[a][b]+1){
		--cnt[dp[a-1][b-1]];
		dp[a-1][b-1]=dp[a][b]+1;
		++cnt[dp[a-1][b-1]];
		rec(a-1, b-1);
	}
	if(a && dp[a-1][b] > dp[a][b]+1){
		--cnt[dp[a-1][b]];
		dp[a-1][b]=dp[a][b]+1;
		++cnt[dp[a-1][b]];
		rec(a-1, b);
	}
	if(b && dp[a][b-1] > dp[a][b]+1){
		--cnt[dp[a][b-1]];
		dp[a][b-1]=dp[a][b]+1;
		++cnt[dp[a][b-1]];
		rec(a, b-1);
	}
}*/

vector<pair<int, int> > has[2000];

void calc(){
	for(int i=0; i <= 2000; ++i)
		has[i].clear();
	for(int i=n; i >= 0; --i)
		for(int j=m; j >= 0; --j){
			if(i == n || j == m){
				dp[i][j]=0;
				continue;
			}
			if(field[i][j] == 'X')
				dp[i][j]=0;
			else
				dp[i][j]=min(min(dp[i+1][j]+1, dp[i][j+1]+1), dp[i+1][j+1]+1);
			has[dp[i][j]].push_back(make_pair(i, j));
		}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i < n; ++i)
		scanf("%s", field[i]);
	calc();
	vector<pair<int, int> > cars;
	for(int i=0; i < k; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		cars.push_back(make_pair(x, y));
		field[x][y]='X';
		if(cars.size() > 50){
			cars.clear();
			calc();
		}
		//--cnt[dp[x][y]];
		//dp[x][y]=0;
		//++cnt[dp[x][y]];
		//rec(x, y);
		/*for(int a=x; a >= 0; --a){
			int b;
			int diff=x-a;
			for(b=y; b >= 0; --b){
				if(diff < y-b)
					diff=y-b;
				if(a == x && b == y)
					continue;
				if(diff < dp[a][b]){
					--cnt[dp[a][b]];
					dp[a][b]=diff;
					++cnt[dp[a][b]];
				}
				else if(y-b > x-a)
					break;
			}
			if(b == y)
				break;
		}*/
		for(int j=2000; j >= 0; --j){
			while(!has[j].empty()){
				pair<int, int> cur=has[j].back();
				bool ok=1;
				for(int a=0; a < cars.size(); ++a){
					if(cars[a].first < cur.first || cars[a].second < cur.second)
						continue;
					int nw=max(cars[a].first-cur.first, cars[a].second-cur.second);
					if(nw < j){
						has[j].pop_back();
						has[nw].push_back(cur);
						ok=0;
						break;
					}
				}
				if(ok)
					break;
			}
			if(!has[j].empty()){
				printf("%d\n", j);
				break;
			}
		}
	}
}