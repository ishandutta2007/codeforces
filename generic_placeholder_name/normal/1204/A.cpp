#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main () {
	string s; int ans; bool c=0;
	cin>>s;
	if (s=="0") cout<<0;
	else{
		for(int i=1; i<s.length(); i++) {
			if (s[s.length()-i]=='1') c=1;
		}
		ans=(s.length()+1)/2;
		if (c==0&&s.length()%2==1) ans--;
		cout<<ans;
	}
}