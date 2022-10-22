#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 100*1000+1;
int n,ans;
int cnt[nax],ile[nax],diff;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int pr=0;
	for(int i=0; i<n;i++) {
		int a;
		cin>>a;
		if(cnt[a]==0) diff++;
		ile[cnt[a]++]--;
		ile[cnt[a]]++;
		ile[0]=0;
		if(ile[cnt[a]]==1&&ile[cnt[a]-1]==diff-1) {
			ans=i+1;
		}
		if(ile[cnt[a]]==diff-1&&ile[cnt[a]+1]==1) {
			ans=i+1;
		}
		if(ile[1]==diff) {
			ans=i+1;
		}
		if(ile[cnt[a]]==diff-1&&ile[1]==1) {
			ans=i+1;
		}
		if(i>0&&ile[cnt[pr]]==diff-1&&cnt[a]==1) {
			ans=i+1;
		}
		//cout<<ile[cnt[a]]<<" "<<cnt[a]<<"\n";
		pr=a;
	}
	cout<<ans;
}