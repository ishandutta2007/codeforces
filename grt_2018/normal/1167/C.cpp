#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 500*1000+1;
int n,m,id;
int group[nax];
vi V[nax];
int C[nax];
int s[nax];

void dfs(int x) {
	C[x]=id;
	s[id]++;
	for(auto nbh:V[x]) {
		if(C[nbh]==0) {
			dfs(nbh);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0; i<m;i++) {
		int k;
		cin>>k;
		for(int j=0; j<k;j++) {
			cin>>group[j];
			if(j>0) {
				V[group[j-1]].PB(group[j]);
				V[group[j]].PB(group[j-1]);
			}
		}
	}
	for(int i=1; i<=n;i++) {
		if(C[i]==0) {
			id++;
			dfs(i);
		}
	}
	for(int i=1; i<=n;i++) {
		cout<<s[C[i]]<<" ";
	}
}