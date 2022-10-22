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

const int nax = 110;
int n, ans;
bool cnt[nax];
bool done[nax];

int main() {_
	cin>>n;
	for(int a,i=0; i<n;i++) {
		cin>>a;
		cnt[a] = 1;
	}
	for(int i=1; i<=100; i++) {
		if(cnt[i]&&!done[i]) {
			ans++;
			for(int j=i; j<=100; j+=i) {
				if(cnt[j]) done[j]=1;
			}
		}
	}
	cout<<ans;
			
}