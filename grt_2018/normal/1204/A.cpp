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

string s;
int x,cnt;

int main() {_
	cin>>s;
	if(s[0]=='0') {
		cout<<"0";
		return 0;
	}
	if(s.size()==1) {
		cout<<"0";
		return 0;
	}
	x = s.size()-1;
	for(int i=0; i<=x; i++) {
		cnt+=s[i]-'0';
	}
	if(cnt==1) x--;
	cout<<max(0,x/2+1);
}