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

const int nax = 200*1000+10,INF=1e9;
int t,n,k;
string s;
int cnt[nax][26];

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>k>>s;
		for(int i=0; i<k; i++) {
			for(int j=0; j<26; j++) {
				cnt[i][j]=0;
			}
		}
		for(int i=0; i<n; i++) {
			cnt[i%k][s[i]-'a']++;
		}
		int ans = 0;
		for(int i=0; i<=(k-1)/2; i++) {
			int tmp = INF;
			if((k&1)&&(i==(k-1)/2)) {
					for(int l=0; l<26; l++) {
					int w = (n/k) - cnt[i][l];
					tmp = min(tmp,w);
					}
				}
			else {	
				for(int l=0; l<26; l++) {
					int w = (n/k)*2;
					w = w-cnt[i][l] - cnt[k-i-1][l];
					tmp = min(tmp,w);
				}
			}
			ans+=tmp;
		}
		cout<<ans<<"\n";
	}
			
			
	
}