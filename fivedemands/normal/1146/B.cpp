#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string t;
string u;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	for(auto c:s){
		if(c!='a') t+=c;
	}
	if(t.size()%2!=0) return cout << ":(\n",0;
	int num=t.size()/2;
	for(int i=0; i*2<t.size() ;i++) if(t[i]!=t[i+num]) return cout << ":(\n",0;
	int len=s.size()-num;
	for(int i=0; i<len ;i++) u+=s[i];
	for(int i=0; i<len ;i++) if(s[i]!='a') u+=s[i];
	if(u!=s) return cout << ":(\n",0;
	for(int i=0; i<len ;i++) cout << s[i];
	cout << '\n';
}