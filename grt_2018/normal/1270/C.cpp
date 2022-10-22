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

const int nax = 100*1000+10;
int t,n;

int main() {_
	cin>>t;
	while(t--) {
		cin>>n;
		ll sum=0,x=0;
		int a;
		for(int i=1; i<=n; i++) {
			cin>>a;
			sum+=a;
			x^=a;
		}
		cout<<"2\n"<<x<<" ";
		sum+=x;
		cout<<sum<<"\n";
	}
	
}