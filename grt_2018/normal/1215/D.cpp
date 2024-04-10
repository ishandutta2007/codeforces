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

const int nax = 200*1000+10;
int n;
string s;
int a,b,cnta,cntb;

int main() {_
	cin>>n>>s;
	for(int i=0; i<n/2; i++) {
		if(s[i]=='?') cnta++;
		else a+=s[i]-'0';
	}
	for(int i=n/2; i<n;i++) {
		if(s[i]=='?') cntb++;
		else b+=s[i]-'0';
	}
	if(a==b&&cnta==cntb) cout<<"Bicarp";
	else if(9*(cnta-cntb)/2>0&&b-a==9*(cnta-cntb)/2) cout<<"Bicarp";
	else if(9*(cntb-cnta)/2>0&&a-b==9*(cntb-cnta)/2) cout<<"Bicarp";
	else cout<<"Monocarp";
		
}