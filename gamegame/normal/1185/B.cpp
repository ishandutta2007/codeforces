#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ss[2]={"NO","YES"};
string s,t;
bool solve(){
	cin >> s >> t;
	int ptr=0;
	for(int i=0; i<s.size() ;i++){
		while(i>0 && ptr<t.size() && t[ptr]!=s[i] && t[ptr]==s[i-1]) ptr++;
		if(ptr>=t.size() || t[ptr]!=s[i]) return false;
		ptr++;
	}
	while(ptr<t.size() && t[ptr]==s.back()) ptr++;
	return ptr==t.size();
}
int main(){
	ios::sync_with_stdio(false);
	int n;cin >> n;while(n--) cout << ss[solve()] << '\n';
}