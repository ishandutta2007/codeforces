#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

struct Pole {
	int l,r,x;
	bool operator < (const Pole&p) const {
		return x<p.x;
	}
};

int n,h,m;
int w[51];
int ans;
Pole t[51];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>h>>m;
	for(int i=0; i<m;i++) {
		cin>>t[i].l>>t[i].r>>t[i].x;
	}
	for(int i=1; i<=n;i++) {
		w[i]=-1;
	}
	sort(t,t+m);
	for(int i=0;i<m;i++) {
		for(int j=t[i].l; j<=t[i].r;j++) {
			if(w[j]==-1) {
				w[j]=t[i].x;
			}
		}
	}
	for(int i=1; i<=n;i++) {
		if(w[i]==-1) {
			ans+=h*h;
		}
		else {
			ans+=w[i]*w[i];
		}
	}
	cout<<ans;
}