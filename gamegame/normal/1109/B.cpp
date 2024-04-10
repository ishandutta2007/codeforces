#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
typedef double dd;
int main(){
	ios::sync_with_stdio(false);
	string s;cin >> s;
	int n=s.size();
	bool bad=true;
	for(int i=0; i<n ;i++){
		if(i*2==n-1) continue;
		if(s[i]!=s[0]) bad=false;
	}
	if(bad) return cout << "Impossible\n",0;
	s=s+s;
	for(int i=0; i<n ;i++){
		int l=i,r=n+i-1;
		bool ok=true;
		for(int j=l; j<=r ;j++){
			if(s[j]!=s[l+r-j]) ok=false;
		}
		bool same=true;
		for(int j=l; j<=r ;j++){
			if(s[j]!=s[j-i]) same=false;
		}
		
		if(ok && !same) return cout << "1\n",0;
	}
	cout << "2\n";
}