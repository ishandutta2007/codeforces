#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>a,b,c,d;
int n;
int x;
ll ans=0;
int ep=0;
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> s >> x;
		if(s=="11") ep++,ans+=x;
		else if(s=="10") b.push_back(x);
		else if(s=="01") c.push_back(x);
		else d.push_back(x);
	}
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	sort(d.begin(),d.end());
	reverse(b.begin(),b.end());
	reverse(c.begin(),c.end());
	reverse(d.begin(),d.end());
	while(b.size()<c.size()){
		d.push_back(c.back());c.pop_back();
	}
	while(b.size()>c.size()){
		d.push_back(b.back());b.pop_back();
	}
	for(int i=0; i<b.size() ;i++) ans+=b[i]+c[i];
	sort(d.begin(),d.end());
	reverse(d.begin(),d.end());
	while(d.size()<ep) d.push_back(0);
	for(int i=0; i<ep ;i++) ans+=d[i];
	cout << ans << endl;
}