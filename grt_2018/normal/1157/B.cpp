#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n;
string s,w;
int c[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	for(int i=1; i<10;i++) {
		cin>>c[i];
	}
	bool bylo=0,moge=1;
	for(int i=0; i<n;i++) {
		if(s[i]-'0'<c[s[i]-'0']&&moge) {
			w+=(char)(c[s[i]-'0']+'0');
			bylo=1;
		}
		else {
			w+=s[i];
		}
		if(s[i]-'0'>c[s[i]-'0']) {
			if(bylo) {
				moge=0;
			}
		}
	}
	cout<<w;
}