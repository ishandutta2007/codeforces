#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 2000+10;
int n,k;
int p[nax][nax];
char t[nax][nax];
int ans;
int memo[nax];
int delta[nax];
pi black[nax];

bool check_rect(int x1,int y1,int x2,int y2) {
	if(x2<x1||y2<y1) return 1;
	//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	int s = p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1];
	if(s==(x2-x1+1)*(y2-y1+1)) return 1;
	return 0;
}

int main() {
	cin>>n>>k;
	for(int i=1; i<=n;i++) {
		for(int j=1; j<=n;j++) {
			cin>>t[i][j];
			int add=-1;
			if(t[i][j]=='W') add=1;
			else add = 0;
			p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+add;
		}
	}
	for(int i=1; i<=n;i++) {
		black[i] = {-1,0};
		for(int j=1; j<=n;j++) {
			if(t[j][i]=='B') {
				black[i].ND = j;
				if(black[i].ST==-1) black[i].ST=j;
			}
		}
	}
	int cntC = 0;
	for(int i=n; i>k; i--) {
		cntC+=check_rect(1,i,n,i);
	}
	for(int i=1; i<=n-k+1; i++) {
		int cntR = 0,cntA = 0;
		//cout<<"ok\n";
		for(int j=n; j>k;j--) {
			cntR+=check_rect(j,1,j,n);
		}
		//cout<<"ok1\n";
		for(int j=1;j<=k;j++) {
			cntA+=(check_rect(j,1,j,i-1)&&check_rect(j,i+k,j,n));
		}
		//cout<<"ok2\n";
		for(int j=1; j<=n-k+1; j++) {
			memo[j] = cntA+cntR+cntC;
			delta[j] = 0;
			if(check_rect(j,1,j,i-1)&&check_rect(j,i+k,j,n)) cntA--;
			if(check_rect(j,1,j,n)) cntR++;
			if(check_rect(j+k,1,j+k,i-1)&&check_rect(j+k,i+k,j+k,n)) cntA++;
			if(check_rect(j+k,1,j+k,n)) cntR--;
		}
		//cout<<"ok\n";
		for(int j=i; j<i+k; j++) {
			if(black[j].ST==-1) delta[1]++;
			else {
				if(black[j].ST>=max(black[j].ND-k+1,1)) {
					delta[max(black[j].ND-k+1,1)]++;
					delta[black[j].ST+1]--;
				}
			}
		}
		int o = 0;
		for(int j=1; j<=n-k+1; j++) {
			//cout<<i<<" "<<j<<" "<<memo[j]<<"\n";
			o+=delta[j];
			ans=max(ans,memo[j]+o);
		}
		if(check_rect(1,i,n,i)) cntC++;
		if(check_rect(1,i+k,n,i+k)) cntC--;
	}
	cout<<ans;
}