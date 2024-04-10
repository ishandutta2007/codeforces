#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;

const int nax = 1000*1000+10;
int n;
string s;
int suf[nax];
long long ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	n=s.size();
	s+='#';
	for(int i=n-1; i>=0;i--) {
		suf[i] = suf[i+1];
		if(s[i]==s[i-1]&&s[i]=='v') suf[i]++;
	}
	int so = 0;
	for(int i=1; i<n-1;i++) {
		if(s[i]==s[i-1]&&s[i]=='v') so++;
		if(s[i]=='o') ans+=(long long)so*(suf[i+1]);
	}
	cout<<ans;
}