#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 300*1000+1;
int n,mini[nax],maxi[nax];
pii a[nax];
int ans=1000*1000*1000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i].ST;
		a[i].ND=i;
	}
	sort(a,a+n);
	mini[n] = 1000*1000*1000;
	for(int i=n-1; i>=0; i--) {
		mini[i]=min(mini[i+1],a[i].ND);
		maxi[i]=max(maxi[i+1],a[i].ND);
	}
	for(int i=0; i<n-1; i++) {
		int dist = max(abs(a[i].ND-maxi[i+1]),abs(a[i].ND-mini[i+1]));
		ans=min(ans,(int)a[i].ST/dist);
	}
	cout<<ans;
}