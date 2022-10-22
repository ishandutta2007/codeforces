#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 100*1000+10;
int n,k;
pii cnt[nax];
int ile;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1; i<=k;i++) {
		int x;
		cin>>x;
		if(cnt[x].ST==0) {
			cnt[x].ST = cnt[x].ND = i;
		}
		else {
			cnt[x].ND = i;
		}
	}
	if(n==1) {
		cout<<"0";
		return 0;
	}
	for(int i=1; i<=n;i++) {
		if(cnt[i].ST==0) continue;
		if(cnt[i+1].ST!=0&&cnt[i+1].ST<cnt[i].ND) {
			ile++;
		}
		if(cnt[i+1].ND!=0&&cnt[i+1].ND>cnt[i].ST) {
			ile++;
		}
		if(cnt[i].ST!=0) ile++;
	}
	int ans = (n-2)*3+4-ile;
	cout<<ans;
}