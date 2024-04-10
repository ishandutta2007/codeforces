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
int n,sx,sy;
int ox[nax],oy[nax];
int ans;
pi d;
int cnt0,cnt1;

int main() {_
	cin>>n>>sx>>sy;
	for(int i=1; i<=n; i++) {
		cin>>ox[i]>>oy[i];
	}
	sort(ox+1,ox+n+1);
	sort(oy+1,oy+n+1);
	for(int i=1; i<=n; i++) {
		if(ox[i]<sx) {
			cnt0++;
		} else if(ox[i]>sx) {
			cnt1++;
		}
	}
	if(ans<cnt0) {
		ans=cnt0;
		d={-1,0};
	}
	if(ans<cnt1) {
		ans=cnt1;
		d={1,0};
	}
	cnt0=cnt1=0;
	for(int i=1; i<=n; i++) {
		if(oy[i]<sy) {
			cnt0++;
		} else if(oy[i]>sy) {
			cnt1++;
		}
	}
	if(ans<cnt0) {
		ans=cnt0;
		d={0,-1};
	}
	if(ans<cnt1) {
		ans=cnt1;
		d={0,1};
	}
	cout<<ans<<"\n";
	cout<<sx+d.ST<<" "<<sy+d.ND;
}