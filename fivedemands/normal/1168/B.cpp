#include<iostream>
using namespace std;
typedef long long ll;
string s;
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	ans=1LL*(s.size())*(s.size()+1)/2;
	for(int i=0; i<s.size() ;i++){
		for(int j=i; j<s.size() ;j++){
			bool ok=false;
			for(int k=1; j-k-k>=i ;k++){
				if(s[j]==s[j-k] && s[j-k]==s[j-k-k]) ok=true;
			}
			if(ok) break;
			ans--;
		}
	}
	cout << ans << endl;
}