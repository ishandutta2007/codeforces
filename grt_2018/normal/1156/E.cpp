#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
const int INF = 1000*1000*1000;
int n,p[nax],inv[nax];
pii seg[nax];
vector<pii> S;
LL ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) {
		cin>>p[i];
		inv[p[i]] = i;
	}
	S.emplace_back(INF,0);
	for(int i=1; i<=n;i++) {
		while(S.back().ST<p[i]) {
			S.pop_back();
		}
		seg[p[i]].ST = S.back().ND+1;
		S.emplace_back(p[i],i);
	}
	S.clear(); S.emplace_back(INF,n+1);
	for(int i=n;i>=1;i--) {
		while(S.back().ST<p[i]) {
			S.pop_back();
		}
		seg[p[i]].ND = S.back().ND-1;
		S.emplace_back(p[i],i);
	}
	for(int i=1; i<=n;i++) {
		int l=seg[i].ST,r=seg[i].ND,mid=inv[i];
		//cout<<l<<" "<<mid<<" "<<r<<"\n";
		if(mid-l<=r-mid) {
			for(int j=l; j<mid;j++) {
				if(inv[i-p[j]]<=r&&inv[i-p[j]]>mid) {
					ans++;
				}
			}
		}
		else {
			for(int j=mid+1; j<=r;j++) {
				if(inv[i-p[j]]>=l&&inv[i-p[j]]<mid) {
					ans++;
				}
			}
		}
	}
	cout<<ans;
}