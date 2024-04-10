#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int m;
int n;
vector<string>v[11];
int f(char c){
	if(c>='a') return (c-'a')*2;
	if(c>='A') return (c-'A')*2+1;
	return 52+c-'0';
}
ll h[11][66][66];
ll g[66][66][66];
ll ft[2][2][2]={{{24,12},{12,4}},{{12,6},{4,1}}};
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		string s;cin >> s;
		v[s.size()].push_back(s);
		reverse(s.begin(),s.end());
		v[s.size()].push_back(s);
		for(auto cur:s) m=max(m,f(cur)+1);
	}
	for(int i=3; i<=10 ;i++){
		sort(v[i].begin(),v[i].end());
		v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		for(auto cur:v[i]) h[i][f(cur[0])][f(cur[i-1])]++;
		for(int p=0; p<m ;p++)
			for(int q=p; q<m ;q++)
				for(int r=q; r<m ;r++){
					g[p][q][r]=0;
					for(int s=0; s<m ;s++) g[p][q][r]=(g[p][q][r]+h[i][p][s]*h[i][q][s]*h[i][r][s])%mod;
				}
		for(int p=0; p<m ;p++)
			for(int q=p; q<m ;q++)
				for(int r=q; r<m ;r++)
					for(int s=r; s<m ;s++){
						int val=g[p][q][r]*g[p][q][s]%mod*g[p][r][s]%mod*g[q][r][s]%mod*ft[p==q][q==r][r==s];
						ans+=g[p][q][r]*g[p][q][s]%mod*g[p][r][s]%mod*g[q][r][s]%mod*ft[p==q][q==r][r==s];
						ans%=mod;
					}
	}
	cout << ans << endl;
}