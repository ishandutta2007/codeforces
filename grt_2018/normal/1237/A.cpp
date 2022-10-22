#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//#define cerr if(false)cerr
//#define debug(x) cerr<<"["<<(#x)<<"] : ["<<(x)<<"]\n";
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 14000+10;
int n;

int main() {_
	cin>>n;
	int add = 1;
	while(n--) {
		int a;
		cin>>a;
		if(a&1) {
			cout<<(a+add)/2<<"\n";
			add = -add;
		} else {
			cout<<a/2<<"\n";
		}
	}
}