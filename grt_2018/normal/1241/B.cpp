#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int q;
string s,t;
bool ok1[27],ok2[27];

int main() {_
	cin>>q;
	while(q--) {
		cin>>s>>t;
		for(int i=0; i<=26; i++) ok1[i] = ok2[i] = 0;
		for(int i=0; i<(int)s.size(); i++) {
			ok1[s[i]-'a']=1;
			ok2[t[i]-'a']=1;
		}
		bool ok=0;
		for(int i=0; i<27; i++) {
			if(ok1[i]&&ok2[i]) {
				ok=1;
			}
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
}