#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int c[222], d[222], td[222];
bool vis[222];
vector<int> e[222];
int n;

int cal(int cur) {
	int ans=n;
	memset(vis, false, sizeof(vis));
	memmove(td, d, sizeof(d));
	while(1) {
		bool found=true;
		while(found) {
			found=false;
			for(int i=1; i<=n; ++i)
				if(!vis[i] && c[i]==cur && td[i]==0) {
					found=true;
					vis[i]=true;
					for(int j=0; j<e[i].size(); ++j)
						--td[e[i][j]];
				}
		}
		found=false;
		for(int i=1; i<=n; ++i) if(!vis[i]) found=true;
		if(!found) break;
		++ans;
		cur=(cur%3)+1;
	}
	return ans;
}

int main() {
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>c[i];
	for(int i=1; i<=n; ++i) d[i]=0, e[i].clear();
	for(int i=1; i<=n; ++i) {
		int k, j; cin>>k;
		while(k--) {
			cin>>j; e[j].push_back(i);
			d[i]++;
		}
	}
	int ans=min(cal(1), min(cal(2), cal(3)));
	cout<<ans<<endl;
	return 0;
}