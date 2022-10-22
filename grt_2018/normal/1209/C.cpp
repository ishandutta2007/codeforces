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
int n,t;
int col[nax];
string s;

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>s;
		int l1 = 0, l2 = 0;
		bool ans = 0;
		for(int x = 0; x<=9; x++) {
			int l1 = 0, l2 = 0; bool ok = 1;
			for(int i=0; i<n;i++) col[i] = 0;
			for(int i=0; i<n;i++) {
				if(s[i]-'0'<x&&s[i]-'0'<l1) ok=0;
				if(s[i]-'0'>x&&s[i]-'0'<l2) ok=0;
				if(s[i]-'0'<x&&s[i]-'0'>=l1) {
					col[i] = 1; l1 =s[i]-'0';
				}
				if(s[i]-'0'>x&&s[i]-'0'>=l2) {
					col[i] = 2; l2 = s[i]-'0';
				}
			}
			for(int i=n-1; i>=0; i--) {
				if(s[i]-'0'==x) col[i] = 1;
				if(s[i]-'0'<x) break;
			}
			for(int i=0; i<n;i++) {
				if(s[i]-'0'==x) col[i] = 2;
				if(s[i]-'0'>x) break;
			}
			for(int i=0; i<n;i++) if(col[i]==0) ok=0;
			if(ok) {
				ans = 1;
				break;
			}
		}
		if(!ans) cout<<"-\n";
		else {
			for(int i=0; i<n;i++) cout<<col[i];
			cout<<"\n";
		}
	}
}