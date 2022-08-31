#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll a[1000001];
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--){
		int x,y,z;
		cin >> x >> y >> z;
		string s;
		for(int i=0; i<z ;i++){
			s+=(char)('a'+i);
		}
		for(int i=z; i<y ;i++) {
			s+='a';
		}
		for(int i=y; i<x ;i++) s+=s[i-y];
		cout << s << '\n';
	}
}