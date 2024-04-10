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

int l,r;
int cnt[10];

bool add(int x) {
	while(x>0) {
		cnt[x%10]++;
		if(cnt[x%10]>1) return 0;
		x/=10;
	}
	return 1;
}

int main() {_
	cin>>l>>r;
	bool ok=0;
	for(int i=l; i<=r; i++) {
		for(int j=0; j<10; j++) cnt[j]=0;
		if(add(i)) {
			ok=1;
			cout<<i<<"\n";
			break;
		}
	}
	if(!ok) cout<<"-1";
}