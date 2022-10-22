#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 100*1000+1;
int n,m;
int b[nax],g[nax];
int ile[nax];
LL ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0; i<n;i++) {
		cin>>b[i];
	}
	for(int j=0; j<m;j++) {
		cin>>g[j];
	}
	sort(b,b+n);
	sort(g,g+m);
	if(b[n-1]>g[0]) {
		cout<<"-1";
		return 0;
	}
	int ind=n-1;
	for(int i=m-1; i>=0; i--) {
		if((ile[ind]==m-1&&g[i]>b[ind])||(ile[ind]==m&&g[i]==b[i])) {
			ind--;
		}
		ile[ind]++;
		ans+=g[i];
	}
	for(int i=0; i<n;i++) {
		ans+=(LL)(m-ile[i])*b[i];
	}
	cout<<ans;
}