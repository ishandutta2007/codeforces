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
int t,n,m,ans;
int mon[nax];
pi hero[nax];

int main() {_
	cin>>t;
	while(t--) {
		ans = 1;
		cin>>m;
		for(int i=0; i<m; i++) cin>>mon[i];
		cin>>n;
		for(int i=0; i<n;i++)cin>>hero[i].ST>>hero[i].ND;
		sort(hero,hero+n);
		for(int i=n-2; i>=0; i--) {
			hero[i].ND = max(hero[i].ND,hero[i+1].ND);
		}
		int mak = 0,dist=0;
		bool ok = 0;
		for(int i=0;i<m;i++) {
			mak = max(mak,mon[i]);
			dist++;
			int l=0,r=n-1,mid;
			while(l<=r) {
				mid = (l+r)/2;
				if(hero[mid].ST>=mak) {
					r = mid-1;
				} else {
					l = mid+1;
				}
			}
			r++;
			//cout<<i<<" "<<ans<<" "<<r<<"\n";
			if(r==n) {
				cout<<"-1\n";
				ok=1;
			}
			if(ok) break;
			if(hero[r].ND<dist) {
				ans++;
				dist=1;
				mak =mon[i];
			}
		}
		if(!ok)
		cout<<ans<<"\n";
	}
			
		
	
}