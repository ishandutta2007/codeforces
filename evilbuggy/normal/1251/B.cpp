#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		int cnt[2] = {0};
		vector<int> len;
		for(int i = 0; i < n; i++){
			cin>>s;
			for(auto ch : s){
				cnt[ch - '0']++;
			}
			len.push_back(s.size());
		}
		sort(len.begin(), len.end());
		int ans = 0;
		for(auto l : len){
			if(l&1){
				int y = l-1;
				if(cnt[0] >= y){
					cnt[0] -= y;
				}else{
					int x = y;
					x -= (cnt[0]/2)*2;
					cnt[0] &= 1;
					if(cnt[1] < x){
						break;
					}
					cnt[1] -= x;
				}
				if(!cnt[0] && !cnt[1])break;
				if(cnt[0]&1)cnt[0]--;
				else cnt[1]--;
				ans++;
			}else{
				if(cnt[0] >= l){
					cnt[0] -= l;
					ans++;
				}else{
					int x = l;
					x -= (cnt[0]/2)*2;
					cnt[0] &= 1;
					if(cnt[1] < x){
						break;
					}
					cnt[1] -= x;
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}