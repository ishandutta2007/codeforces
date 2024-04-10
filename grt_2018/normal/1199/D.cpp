#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 2*100*1000+10;
int n,q;
int a[nax],ev[nax],b[nax],suf[nax],ans[nax];
pi last[nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n;i++) {
		cin>>a[i];
		last[i] = {0,a[i]};
	}
	cin>>q;
	for(int t,p,x,i=1; i<=q;i++) {
		cin>>t;
		if(t==1) {
			cin>>p>>x;
			last[p] = {i,x};
		} else {
			cin>>x;
			b[i] = x;
		}
	}
	for(int i=q; i>=0;i--) {
		suf[i] = max(suf[i+1],b[i]);
	}
	for(int i=1; i<=n;i++) {
		cout<<max(last[i].ND,suf[last[i].ST])<<" ";
	}
		
}