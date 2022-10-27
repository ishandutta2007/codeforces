#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll solve(){
	string s;
	cin>>s;
	string sr = s; reverse(sr.begin(), sr.end());
	int n = s.size();
	vector<int> mu(n), md(n), ml(n), mr(n);
	int cmu = 0, cmd = 0, cml = 0, cmr = 0;
	int x = 0, y = 0;
	for(int i = 0; i < n; i++){
		if(sr[i] == 'W'){
			y--;
		}else if(sr[i] == 'S'){
			y++;
		}else if(sr[i] == 'A'){
			x++;
		}else{
			x--;
		}
		cmu = max(cmu, y);
		cmd = max(cmd, -y);
		cml = max(cml, -x);
		cmr = max(cmr, x);
		mu[n-i-1] = cmu - y;
		md[n-i-1] = cmd + y;
		ml[n-i-1] = cml + x;
		mr[n-i-1] = cmr - x;
	}
	ll ans = (cmu + cmd + 1)*1LL*(cml + cmr + 1);
	x = 0, y = 0;
	cmu = cmd = cml = cmr = 0;
	for(int i = 0; i + 1 < n; i++){
		if(s[i] == 'W'){
			y++;
		}else if(s[i] == 'S'){
			y--;
		}else if(s[i] == 'A'){
			x--;
		}else{
			x++;
		}
		cmu = max(cmu, y);
		cmd = max(cmd, -y);
		cml = max(cml, -x);
		cmr = max(cmr, x);
		// W
		{
			y++;
			int nmu = max(cmu, mu[i+1] + y);
			int nmd = max(cmd, md[i+1] - y);
			int nml = max(cml, ml[i+1] - x);
			int nmr = max(cmr, mr[i+1] + x);
			ans = min(ans, (nmu + nmd + 1)*1LL*(nml + nmr + 1));
			y--;
		}
		// S
		{
			y--;
			int nmu = max(cmu, mu[i+1] + y);
			int nmd = max(cmd, md[i+1] - y);
			int nml = max(cml, ml[i+1] - x);
			int nmr = max(cmr, mr[i+1] + x);
			ans = min(ans, (nmu + nmd + 1)*1LL*(nml + nmr + 1));
			y++;
		}
		// A
		{
			x--;
			int nmu = max(cmu, mu[i+1] + y);
			int nmd = max(cmd, md[i+1] - y);
			int nml = max(cml, ml[i+1] - x);
			int nmr = max(cmr, mr[i+1] + x);
			ans = min(ans, (nmu + nmd + 1)*1LL*(nml + nmr + 1));
			x++;
		}
		// D
		{
			x++;
			int nmu = max(cmu, mu[i+1] + y);
			int nmd = max(cmd, md[i+1] - y);
			int nml = max(cml, ml[i+1] - x);
			int nmr = max(cmr, mr[i+1] + x);
			ans = min(ans, (nmu + nmd + 1)*1LL*(nml + nmr + 1));
			x--;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)cout<<solve()<<endl;

	return 0;
}