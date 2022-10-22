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

const int nax = 100*1000+10;
const ll INF=1e18;

int t,n1,n2,n3;
int a[nax];
int b[nax];
int c[nax];
vector<int>v[3];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n1 >> n2 >> n3;
		for(int i = 1; i <= n1; ++i) {
			cin >> a[i];
		}
		for(int i = 1; i <= n2; ++i) {
			cin >> b[i];
		}
		for(int i = 1; i <= n3; ++i) {
			cin >> c[i];
		}
		sort(a+1,a+n1+1);
		sort(b+1,b+n2+1);
		sort(c+1,c+n3+1);
		for(int i = 1; i <= n1; ++i) {
			v[0].PB(a[i]);
		}
		for(int i = 1; i <= n2; ++i) {
			v[1].PB(b[i]);
		}
		for(int i = 1; i <= n3; ++i) {
			v[2].PB(c[i]);
		}
		vi tmp = {0,1,2};
		ll ans = 2*INF;
		do {
			int wsk1 = -1, wsk2 = 0;
			//cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << "\n";
			for(int i = 0; i < (int)v[tmp[0]].size(); ++i) {
				//cout << v[tmp[0]][i] << " ";
				while(wsk1 + 1 < (int)v[tmp[1]].size() && v[tmp[1]][wsk1 + 1] <= v[tmp[0]][i]) {
					wsk1++;
				}
				while(wsk2 < (int)v[tmp[2]].size() && v[tmp[2]][wsk2] < v[tmp[0]][i]) {
					wsk2++;
				}
				if(wsk1 > -1 && wsk1 < (int)v[tmp[1]].size()) {
					if(wsk2 < (int)v[tmp[2]].size()) {
						int q = v[tmp[0]][i];
						int w = v[tmp[1]][wsk1];
						int e = v[tmp[2]][wsk2];
						//cout << q << " " << w << " " << e << "\n";
						ans = min(ans,((ll)(q-w)*(q-w) + (ll)(q-e)*(q-e) + (ll)(w-e)*(w-e)));
					}
				}
			}
			//cout << "\n";
			//cout << "\n";
		} while(next_permutation(tmp.begin(),tmp.end()));
		cout << ans << "\n";
		for(int i =0 ; i<3; ++i) v[i].clear();
	}
	
}