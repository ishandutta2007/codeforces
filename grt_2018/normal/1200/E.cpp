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

const int nax = 100*1000+10,kax = 2e6+10;
int n;
string ans;
int p[kax];

int kmp(string &s) {
	p[1] = 0;
	for(int i=2; i<=(int)s.size(); i++) {
		int w = p[i-1];
		while(w>0&&s[w]!=s[i-1]) w = p[w];
		if(s[w]==s[i-1]) w++;
		p[i]=w;
	}
	return p[(int)s.size()];
}

int main() {_
	cin>>n;
	cin>>ans;
	for(int i=1; i<n;i++) {
		string s;
		cin>>s;
		string tmp = s+'#';
		for(int i=max(0,(int)ans.size()-(int)s.size()); i<(int)ans.size();i++) {
			tmp+=ans[i];
		}
		int w = kmp(tmp);
		for(int i=w; i<(int)s.size();i++) {
			ans+=s[i];
		}
	}
	cout<<ans;
}