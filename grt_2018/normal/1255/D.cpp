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

const int nax = 110;
int t,r,c,k,R,last;
bool ar[nax][nax];
char ans[nax][nax];

void nexte() {
	if(last==90) last=97;
	else if(last==122) last=48;
	else last++;
}

int main() {_
	cin>>t;
	while(t--) {
		cin>>r>>c>>k;
		R=0;
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++) {
				char tmp;
				cin>>tmp;
				if(tmp=='R') ar[i][j] = 1;
				else ar[i][j]=0;
				R+=ar[i][j];
			}
		}
		last=65;
		int diff=1;
		int ile = R%k,x=R/k,act=0;
		for(int i=1; i<=r; i++) {
			if(i%2==1)
			for(int j=1; j<=c; j++) {
				act+=ar[i][j];
				ans[i][j] = (char)last;
				if(act==x+(ile>0)) {
					if(diff<k){
						nexte();diff++;
					}
					act=0;
					ile--;
				}
			}
			else {
				for(int j=c; j>=1; j--) {
				act+=ar[i][j];
				ans[i][j] = (char)last;
				if(act==x+(ile>0)) {
					if(diff<k) {
						nexte();diff++;
					}
					act=0;
					ile--;
				}
			}
		}
		}
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++) {
				cout<<ans[i][j];
			}
			cout<<"\n";
		}
	}
		
		
		
	
}