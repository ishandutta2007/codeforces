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
int n, ans;
string s;
pi light[nax];

int main() {_
	cin>>n;
	cin>>s;
	for(int i=0; i<n;i++) {
		cin>>light[i].ST>>light[i].ND;
	}
	for(int step=0; step<=200; step++) {
		for(int i=0; i<n;i++) {
			if(step>=light[i].ND&&(step-light[i].ND)%light[i].ST==0) {
				s[i] = '1' - s[i] + '0';
			}
		}
		int cnt = 0;
		for(auto it:s) if(it=='1') cnt++;
		ans= max(ans,cnt);
	}
	cout<<ans;
			
}