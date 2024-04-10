#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
string s,t;
int n,m;
int pre[N],suf[N];
void solve(){
	cin >> s >> t;
	n=s.size();m=t.size();
	s='?'+s;t='?'+t;
	for(int i=1; i<=n ;i++){
		pre[i]=0;suf[i]=0;
		for(int j=1; j<=n-i+1 ;j++){
			if(s[i+j-1]==t[j]) pre[i]++;
			else break;
		}
		for(int j=1; j<=n-i+1 ;j++){
			if(s[i+j-1]==t[m-j+1]) suf[i]++;
			else break;
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if((i+j)%2==m%2) continue;
			int frog=(m+j+i-1)/2;
			if(pre[i]>frog-i && suf[j]>frog-j){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}