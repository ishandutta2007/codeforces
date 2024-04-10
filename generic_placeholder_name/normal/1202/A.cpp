#include <bits/stdc++.h>

#define ll long long

using namespace std;
int next_1(string s, int l) {
	int i=l; while(s[i]!='1') i++; return i;	
}

int main() {
	int q; cin>>q;
	for(int l=1; l<=q; l++) {
		string x, y; cin>>x>>y; reverse(x.begin(), x.end()); reverse(y.begin(), y.end());
		cout<<max(next_1(x, next_1(y, 0))-next_1(y, 0), 0)<<endl;
	}
}