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

int a1,a2,k1,k2,n,ans1,ans2;

int main() {_
	cin>>a1>>a2>>k1>>k2>>n;
	ans1 = min(a1,n/k1)+min(a2,(n-min(a1,n/k1)*k1)/k2);
	ans2 = min(a2,n/k2)+min(a1,(n-min(a2,n/k2)*k2)/k1);
	cout<<max(0,n-(k1-1)*a1-(k2-1)*a2)<<" "<<max(ans1,ans2);
		
	
}