#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
int n,nrw,nrb;
vector<pii> V[nax];
int white[nax];
int black[nax];
int r_w[nax],r_b[nax];
LL ans;

void dfs_w(int x) {
	white[x] = nrw;
	r_w[nrw]++;
	for(auto nbh:V[x]) {
		if(white[nbh.ST]==0&&nbh.ND==0) {
			dfs_w(nbh.ST);
		}
	}
}

void dfs_b(int x) {
	black[x] = nrb;
	r_b[nrb]++;
	for(auto nbh:V[x]) {
		if(black[nbh.ST]==0&&nbh.ND==1) {
			dfs_b(nbh.ST);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int a,b,c,i=1; i<n;i++) {
		cin>>a>>b>>c;
		V[a].PB({b,c});
		V[b].PB({a,c});
	}
	for(int i=1; i<=n;i++) {
		if(white[i]==0) {
			nrw++;
			dfs_w(i);
		}
		if(black[i]==0) {
			nrb++;
			dfs_b(i);
		}
	}
	for(int i=1; i<=nrw;i++) {
		ans+=(LL)r_w[i]*(r_w[i]-1);
	}
	for(int i=1;i<=nrb;i++) {
		ans+=(LL)r_b[i]*(r_b[i]-1);
	}
	for(int i=1; i<=n;i++) {
		ans+=(LL)(r_b[black[i]]-1)*(r_w[white[i]]-1);
	}
	cout<<ans;
}