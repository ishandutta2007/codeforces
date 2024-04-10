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

const int nax = 200*1000+10,mod = 1e9+7,INF=1e9;
int n;
pi in[nax];
pi s[nax];

int main() {_
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>in[i].ND>>in[i].ST;
	}
	sort(in,in+n);
	s[n] = {INF,0};
	for(int i = n-1; i>=0; i--) {
		int l = i+1,r=n-1,mid;
		while(l<=r) {
			mid = (l+r)/2;
			if(in[i].ND<=in[mid].ST) r = mid-1;
			else l = mid+1;
		}
		pi tmp;
		if(r+1==n) {
			tmp = {in[i].ST,1};
		} else {
			tmp = {s[r+1].ST+in[i].ST-in[i].ND,s[r+1].ND};
		}
		//cout<<tmp.ST<<" "<<tmp.ND<<"\n";
		if(tmp.ST>s[i+1].ST) s[i] = s[i+1];
		else if(tmp.ST==s[i+1].ST) s[i] = {s[i+1].ST,(s[i+1].ND+tmp.ND)%mod};
		else s[i] = tmp;
	}
	cout<<s[0].ND;
}