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

int a,b,ans;

int main() {
	cout<<"? ";
	for(int i=1; i<=100; i++) {
		cout<<i*(1<<7)<<" ";
	}
	cout<<"\n";
	fflush(stdout);
	cin>>a;
	cout<<"? ";
	for(int i=1; i<=100; i++) {
		cout<<i<<" ";
	}
	cout<<"\n";
	fflush(stdout);
	cin>>b;
	for(int i=0; i<7; i++) {
		if((a&(1<<i))) {
			ans+=(1<<i);
		}
	}
	for(int i=7; i<14; i++) {
		if((b&(1<<(i)))) {
			ans+=(1<<i);
		}
	}
	cout<<"! "<<ans<<"\n";
	fflush(stdout);
}