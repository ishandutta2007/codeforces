#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s >> t;
	while(s.back()==t.back()) s.pop_back(),t.pop_back();
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	while(s.back()==t.back()) s.pop_back(),t.pop_back();
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	bool ok1=true,ok2=true;
	for(int i=1; i<s.size() ;i++){
		if(s[i]!=t[i-1]) ok1=false;
		if(t[i]!=s[i-1]) ok2=false;
	}
	cout << (int)ok1+ok2 << endl;
}