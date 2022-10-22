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

int k,b;

int main() {_
	cin>>k;
	int last = -1;
	if(k==0) {
		cout<<"1 1\n1";
		return 0;
	}
	for(int i=0; i<20; i++) {
		if((1<<i)&k) last = i;
	}
	b = (1<<(last+1));
	cout<<3<<" "<<4<<"\n";
	cout<<k+b<<" "<<k<<" "<<k<<" 0\n";
	cout<<b<<" 0 "<<k<<" 0\n";
	cout<<b<<" "<<b<<" "<<b+k<<" "<<k;
	
}