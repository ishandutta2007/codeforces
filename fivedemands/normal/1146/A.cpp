#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	int cnt=0;
	for(auto c:s) cnt+=c=='a';
	cout << min(cnt*2-1,(int)s.size());
}