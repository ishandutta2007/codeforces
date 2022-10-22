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

int n;

int main() {_
	cin>>n;
	for(int i=0; i<n ;i++) {
		for(int j=0; j<n ;j++) {
			if((i+j)%2==0) cout<<"W";
			else cout<<"B";
		}
		cout<<"\n";
	}
}