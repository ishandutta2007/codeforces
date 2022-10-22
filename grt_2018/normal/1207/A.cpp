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

int t,b,p,f,h,c;

int main() {_
	cin>>t;
	while(t--) {
		cin>>b>>p>>f>>h>>c;
		int sum = 0;
		if(h>c) {
			int x = min(b/2,p);
			sum+=x*h;
			b-=2*x;
			int y = min(b/2,f);
			sum+=y*c;
		} else {
			int x =min(b/2,f);
			sum+=x*c;
			b-=2*x;
			int y = min(b/2,p);
			sum+=y*h;
		}
		cout<<sum<<"\n";
	}
}