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
int n,sum,s1;
int a[nax];

int main() {_
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	for(int i=0; i<n/2; i++) s1+=a[i];
	cout<<(ll)s1*s1+(ll)(sum-s1)*(sum-s1);
	
}