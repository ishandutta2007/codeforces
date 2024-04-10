#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n,k,r;
string s;
vector<char> v[200005];
int cnt[30];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		cin>>s;
		
		for (int x=0;x<s.size();x++) v[x].clear();
		
		r=n/k; //number of rep
		
		for (int x=0;x<s.size();x++){
			int pos=x%k;
			if (pos<(k+1)/2) v[pos].push_back(s[x]);
			else v[k-1-pos].push_back(s[x]);
		}
		
		int ans=0;
		for (int x=0;x<s.size();x++) if (!v[x].empty()) {
			memset(cnt,0,sizeof(cnt));
			for (auto &it:v[x]) cnt[it-'a']++;
			int best=0;
			for (int y=0;y<26;y++) best=max(best,cnt[y]);
			ans+=v[x].size()-best;
		}
		
		cout<<ans<<endl;
	}
}