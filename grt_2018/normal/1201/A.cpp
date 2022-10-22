#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1000+10;
int n,m;
string s[nax];
int cnt[5];
int points[nax];
ll ans;

int main() {_
	cin>>n>>m;
	for(int i=0; i<n;i++) {
		cin>>s[i];
	}
	for(int i=0; i<m;i++) {
		cin>>points[i];
	}
	for(int i=0; i<m;i++) {
		for(int j=0; j<5;j++) cnt[j]=0;
		for(int j=0; j<n;j++) {
			cnt[s[j][i]-'A']++;
		}
		int ma = 0;
		for(int j=0; j<5;j++) ma=max(ma,cnt[j]);
		ans+=(ll)ma*points[i];
	}
	cout<<ans;
		
}