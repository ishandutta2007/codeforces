#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n,k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	int d = (n-k)/2;
	for(int i=1; i<=n;i++) {
		if(i%(d+1)==0) {
			cout<<"1";
		}else {
			cout<<"0";
		}
	}
}