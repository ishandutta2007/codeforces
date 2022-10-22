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

int n,k;
string s;
string t;

int main() {_
	cin>>n>>k>>s;
	t = s.substr(0,k);
	for(int i=k; i<n; i++) t+=t[i-k];
	cout<<n<<"\n";
	if(t>=s) {
		cout<<t;
	}else {
		for(int i=k-1; i>=0;i--) {
			if(t[i]=='9') t[i]='0';
			else {
				t[i]++;
				break;
			}
		}
		for(int i=k; i<n; i++) {
			t[i] = t[i-k];
		}
		cout<<t;
	}
		
	
}