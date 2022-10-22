#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 200*1000+1;
int n,m,ta,tb,k;
LL a[nax],b[nax];
LL ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>ta>>tb>>k;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		a[i]+=ta;
	}
	for(int i=0; i<m;i++) {
		cin>>b[i];
	}
	if(min(n,m)<=k) {
		cout<<"-1";
		return 0;
	}
	int ind1=0;
	for(int i=0; i<k+1;i++) {
		while(ind1<m&&b[ind1]<a[i]) {
			ind1++;
		}
		int res = ind1+(k-i);
		if(res>=m) {
			cout<<"-1";
			return 0;
		}
		if(ind1==m) break;
		ans=max(ans,b[res]+tb);
	}
	cout<<ans;		
}