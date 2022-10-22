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

const int nax = 500*1000+1,SQRT = 800;
int a[nax];
int ans[SQRT][SQRT];
int q;

int main() {_
	cin>>q;
	while(q--) {
		int t,x,y;
		cin>>t>>x>>y;
		if(t==1) {
				for(int i=1; i<SQRT; i++) {
					ans[x%i][i]-=a[x];
				}
			a[x]+=y;
				for(int i=1; i<SQRT; i++) {
					ans[x%i][i]+=a[x];
				}
		} else {
			int w = 0;
			if(x>=SQRT) {
				for(int i = y; i<nax; i+=x) {
					w+=a[i];
				}
			} else {
				w = ans[y][x];
			}
			cout<<w<<"\n";
		}
	}
}