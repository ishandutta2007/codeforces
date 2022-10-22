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

const int nax = 200*1000+10;
int t;
string s;

int main() {_
	cin>>t;
	while(t--) {
		int ans = 0;
		int cnt = 0, num = 0;
		cin>>s;
		for(int i=0; i<(int)s.size(); i++) {
			if(s[i]=='0') cnt++;
			else {
				num = 0;
				for(int j=i; j<i+20&&j<(int)s.size(); j++) {
					num += s[j] - '0';
					if(j-i+1<=num&&num<=j-i+1+cnt) ans++;
					num*=2;
				}
				cnt = 0;
			}
		}
		cout<<ans<<"\n";
	}
}