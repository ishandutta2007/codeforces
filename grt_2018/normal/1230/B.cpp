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

string s;
int n,k;

int main() {_
	cin>>n>>k>>s;
	int wsk = 0;
	if(n==1&&k==1) {
		cout<<"0";
		return 0;
	}
	while(wsk<n&&k>0) {
		if(wsk==0) {
			if(s[0]!='1') {
				s[0]='1';
				k--;
			}
		} else {
			if(s[wsk]!='0') {
				s[wsk] = '0';
				k--;
			}
		}
		wsk++;
	}
	cout<<s;
}