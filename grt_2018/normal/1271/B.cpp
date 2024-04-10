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

const int nax = 210;
int n;
vi ans1,ans2;
string s,s1;

int main() {_
	cin>>n>>s;
	s1 = s;
	for(int i=0; i<n-1; i++) {
		if(s[i]=='B') {
			ans1.PB(i+1);
			if(s[i+1]=='W') s[i+1]='B';
			else s[i+1]='W';
		}
	}
	if(s[n-1]=='W') {
		cout<<(int)ans1.size()<<"\n";
		for(auto it:ans1) {
			cout<<it<<" ";
		}
		return 0;
	}
	for(int i=0; i<n-1; i++) {
		if(s1[i]=='W') {
			ans2.PB(i+1);
			if(s1[i+1]=='W') s1[i+1]='B';
			else s1[i+1]='W';
		}
	}
	if(s1[n-1]=='B') {
		cout<<(int)ans2.size()<<"\n";
		for(auto it:ans2) {
			cout<<it<<" ";
		}
		return 0;
	}
	cout<<"-1";
		
}