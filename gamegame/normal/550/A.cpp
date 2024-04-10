#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
set<int>p,q;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	string s;cin >> s;
	int n=s.size();s='?'+s;
	for(int i=1; i<n ;i++){
		if(s[i]=='A' && s[i+1]=='B') p.insert(i);
		if(s[i]=='B' && s[i+1]=='A') q.insert(i);
	}
	if(p.size()==0 || q.size()==0) return cout << "NO\n",0;
	if(p.size()==1){
		for(auto c:q){
			if(abs(c-*p.begin())!=1) return cout << "YES\n",0;
		}
		return cout << "NO\n",0;
	}
	p.swap(q);
	if(p.size()==1){
		for(auto c:q){
			if(abs(c-*p.begin())!=1) return cout << "YES\n",0;
		}
		return cout << "NO\n",0;
	}
	cout << "YES\n";
}