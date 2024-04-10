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

const int nax = 1000*1000+10;
int n,act;
vi ans;
int a[nax];
bool in[nax],was[nax];

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	ans.PB(0);
	for(int i=1; i<=n; i++) {
		if(a[i]<0) {
			if(!in[-a[i]]) {
				cout<<"-1";
				return 0;
			}
			in[-a[i]] = 0;
			act--;
		} else {
			if(was[a[i]]) {
				cout<<"-1";
				return 0;
			}
			if(in[a[i]]) {
				cout<<"-1";
				return 0;
			}
			in[a[i]] = 1;
			was[a[i]] = 1;
			act++;
		}
		//cout<<i<<" : "<<act<<"\n";
		if(act==0) {
			ans.PB(i);
			for(int j=ans[ans.size()-2]+1; j<=i; j++) {
				was[abs(a[j])]=0;
			}
		}
	}
	if(ans.back()!=n) {
		cout<<"-1";
		return 0;
	}
	cout<<(int)ans.size()-1<<"\n";
	for(int i=1; i<(int)ans.size(); i++) {
		cout<<ans[i] - ans[i-1]<<" ";
	}
	
}