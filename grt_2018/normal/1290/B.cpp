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

const int nax = 200*1000+10;
int q;
string s;
int p[nax][26];

int main() {_
	cin>>s>>q;
	for(int i=1; i<=(int)s.size(); i++) {
		for(int j=0; j<26; j++) p[i][j] = p[i-1][j];
		p[i][s[i-1]-'a']++;
	}
	while(q--) {
		int a,b;
		cin>>a>>b;
		if(s[a-1]!=s[b-1]) cout<<"Yes\n";
		else if(a==b) cout<<"Yes\n";
		else {
			int cnt = 0;
			for(int i=0; i<26; i++) if(p[b][i]-p[a-1][i]>0) cnt++;
			if(cnt>2) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	
}