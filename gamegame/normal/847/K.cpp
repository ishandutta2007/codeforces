#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
string s[301],t[301];
int n;
int a,b;
int f,k;
map<string,int>mp;
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> a >> b >> k >> f;
	int ans=0;
	for(int i=1; i<=n ;i++){
		cin >> s[i] >> t[i];
		mp[min(s[i],t[i])+"#"+max(s[i],t[i])]+=(s[i]==t[i-1]?b:a);
		ans+=(s[i]==t[i-1]?b:a);
	}
	for(auto cur:mp) v.push_back(cur.se);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i=0; i<min(k,(int)v.size()) ;i++){
		if(v[i]<f) break;
		ans-=v[i]-f;
	}
	cout << ans << endl;
}