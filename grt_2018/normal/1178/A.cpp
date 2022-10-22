#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;

const int nax = 110;
int n,a[nax],s,all;
vi p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	p.PB(1);
	cin>>n;
	for(int i=1; i<=n;i++) {
		cin>>a[i];
		all+=a[i];
		if(2*a[i]<=a[1]) {
			p.PB(i); s+=a[i];
		}
	}
	s+=a[1];
	if(2*s>all) {
		cout<<p.size()<<"\n";
		for(auto it:p) cout<<it<<" ";
	}
	else cout<<"0";
}