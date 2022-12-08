#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=100010;
const int MOD=(int)1E9+7;
#define PB push_back

int s[MAXN], t[MAXN];
vector<int> pre[MAXN];
vector<int> sta;
int f[MAXN], sf[MAXN];
int n, m;

int main() {
	scanf("%d%d", &n,&m);
	sta.clear();
	sta.PB(0); sta.PB(n);
	for(int i=1; i<=m; ++i) {
		scanf("%d%d", s+i,t+i);
		sta.PB(t[i]);
	}
	sort(sta.begin(), sta.end());
	sta.erase(unique(sta.begin(), sta.end()), sta.end());
	for(int i=1; i<=m; ++i) {
		int j=lower_bound(sta.begin(), sta.end(), t[i])-sta.begin();
		pre[j].push_back(s[i]);
	}
	f[0]=sf[0]=1;
	for(int i=1; i<(int)sta.size(); ++i) {
		f[i]=0;
		for(int j=0; j<(int)pre[i].size(); ++j) {
			int k=pre[i][j];
			k=lower_bound(sta.begin(), sta.end(), k)-sta.begin();
			f[i]=(f[i]+sf[i-1])%MOD;
			if(k>0) f[i]=(f[i]-sf[k-1]+MOD)%MOD;
		}
		sf[i]=(sf[i-1]+f[i])%MOD;
	}
	printf("%d\n", f[sta.size()-1]);
	return 0;
}