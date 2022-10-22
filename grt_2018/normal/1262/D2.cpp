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
int n,m,nr;
int a[nax],rev[nax];
vector<pi> q[nax];
map<int,int>sc;
vi pos[nax];
int T[(1<<19)],R;
int ans[nax];

void update(int a,int x) {
	a+=R;
	T[a]+=x;
	while(a>1) {
		a/=2;
		T[a] = T[2*a]+T[2*a+1];
	}
}

int kthsamll(int x) {
	int v=1;
	while(v<R) {
		if(T[2*v]>=x) v*=2;
		else {
			x-=T[2*v];
			v=v*2+1;
		}
	}
	return v-R;
}

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sc[a[i]];
	}
	cin>>m;
	R=1;
	while(R<=n) {
		R*=2;
	}
	for(int i=1; i<=m; i++) {
		int b,c;
		cin>>b>>c;
		q[b].PB({c,i});
	}
	for(auto &it:sc) {
		rev[nr] = it.ST;
		it.ND = nr++;
	}
	for(int i=1; i<=n; i++) {
		pos[sc[a[i]]].PB(i);
	}
	for(int i=0; i<=n; i++) reverse(pos[i].begin(),pos[i].end());
	int x = nr-1;
	for(int k=1; k<=n; k++) {
		while(x>=0&&(int)pos[x].size()==0) x--;
		update(pos[x].back(),1);
		//cout<<"P : "<<pos[x].back()<<"\n";
		pos[x].pop_back();
		for(auto it:q[k]) {
			//cout<<"Q : "<<it.ND<<" "<<it.ST<<" "<<kthsamll(it.ST)<<"\n";
			ans[it.ND] = a[kthsamll(it.ST)];
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<"\n";
	}
	
}