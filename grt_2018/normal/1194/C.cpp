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

int q,n,m,k;
string s,t,p;
int cntt[26],cntp[26];

int main() {_
	cin>>q;
	while(q--) {
		cin>>s>>t>>p;
		n = s.size(); m=t.size(); k=p.size();
		if(n>m) {cout<<"no\n"; continue;}
		for(int i=0; i<26;i++) cntt[i] = cntp[i] = 0;
		int wsk = 0;
		bool ok=1;
		for(int i=0; i<n;i++) {
			while(wsk<m&&t[wsk]!=s[i]) {
				cntt[t[wsk]-'a']++;
				wsk++;
			}
			if(wsk<m&&t[wsk]==s[i]) {
				wsk++;
			} else {
				ok=0;
			}
		}
		for(int i=wsk; i<m;i++) cntt[t[i]-'a']++;
		if(!ok) {cout<<"no\n"; continue;}
		for(auto it:p) cntp[it-'a']++;
		for(int i=0; i<26;i++) {
			if(cntt[i]>cntp[i]) ok=0;
		}
		if(!ok) {cout<<"no\n";}
		else cout<<"yes\n";
	}
}