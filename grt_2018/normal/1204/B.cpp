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

int n,l,r;
ll sum1,sum2;

int main() {_
	cin>>n>>l>>r;
	for(int i=0; i<r;i++) {
		sum1+=(1<<i);
	}
	for(int i=r; i<n;i++) {
		sum1+=(1<<(r-1));
	}
	for(int i=0; i<l;i++) {
		sum2+=(1<<i);
	}
	for(int i=l; i<n;i++) {
		sum2+=1;
	}
	cout<<sum2<<" "<<sum1;
}