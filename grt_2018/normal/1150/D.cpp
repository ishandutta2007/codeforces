#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 100*1000+1;
const int kax = 251;
const int INF = 1000*1000*1000;
int n,q;
int dp[kax][kax][kax],gdzie[nax][26],last[26];
string s;
vector<char> sl[3];

void get_state(int a,int b,int c) {
	dp[a][b][c] = INF;
	if(a>0&&dp[a-1][b][c]!=INF) {
		dp[a][b][c] = min(gdzie[dp[a-1][b][c]+1][sl[0][a-1]-'a'],dp[a][b][c]);
	}
	if(b>0&&dp[a][b-1][c]!=INF) {
		dp[a][b][c] = min(gdzie[dp[a][b-1][c]+1][sl[1][b-1]-'a'],dp[a][b][c]);
	}
	if(c>0&&dp[a][b][c-1]!=INF) {
		dp[a][b][c] = min(gdzie[dp[a][b][c-1]+1][sl[2][c-1]-'a'],dp[a][b][c]);
	}
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin>>n>>q>>s;
    for(int i=0; i<26;i++) {
		last[i]=gdzie[n][i] = INF;
	}
	for(int i=n-1; i>=0;i--) {
		last[s[i]-'a']=i;
		for(int j=0; j<26;j++) {
			gdzie[i][j] = last[j];
		}
	}
	dp[0][0][0] = -1;
	while(q--) {
		char c,y;
		int x;
		cin>>c>>x;
		if(c=='-') {
			sl[--x].pop_back();
		}
		else {
			cin>>y;
			sl[--x].PB(y);
			if(x==0) {
				for(int i=0; i<=sl[1].size();i++) {
					for(int j=0; j<=sl[2].size();j++) {
						get_state(sl[0].size(),i,j);
					}
				}
			}
			else if(x==1) {
				for(int i=0; i<=sl[0].size();i++) {
					for(int j=0; j<=sl[2].size();j++) {
						get_state(i,sl[1].size(),j);
					}
				}
			}
			else {
				for(int i=0; i<=sl[0].size();i++) {
					for(int j=0; j<=sl[1].size();j++) {
						get_state(i,j,sl[2].size());
					}
				}
			}
				
		}
		//for(int i=0; i<=sl[0].size();i++) {
		//	for(int j=0; j<=sl[1].size();j++) {
		//		for(int ij=0; ij<=sl[2].size();ij++) {
		//			cout<<i<<" "<<j<<" "<<ij<<" : "<<dp[i][j][ij]<<"\n";
		//		}
		//	}
		//}
		//cout<<dp[sl[0].size()][sl[1].size()][sl[2].size()]<<"\n";
		if(dp[sl[0].size()][sl[1].size()][sl[2].size()]<INF) {
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
	}
}