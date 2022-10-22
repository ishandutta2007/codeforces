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

const int nax = 200*1000+10;
int n,k[3],ans;
int t[nax];

int main() {_
	cin>>k[0]>>k[1]>>k[2];
	n = k[0]+k[1]+k[2];
	for(int m:{0,1,2}) {
		for(int a,i=0; i<k[m]; i++) {
			cin>>a;
			t[a] = m+1;
		}
	}
	int act=ans=n-k[0],cnt2=0,add=0;
	for(int i=n; i>=1; i--) {
		if(t[i]==1) act++;
		else if(t[i]==2) {
			cnt2++;
			act--;
		} else {
			add++;
			act--;
			if(cnt2<add) {
				add = cnt2;
			}
		}
		ans=min(ans,act+add);
	}
	cout<<ans;
}