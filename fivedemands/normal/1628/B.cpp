#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e5+1;
const int iu=1e6+1;
ll n,m,k;
const ll mod=1e9+7;
int a[729*729];
int sz=0;
int use[729*729];
int en(string &s){
	int cur=0;
	for(auto c:s){
		cur=(c-'a'+1)+cur*27;
	}
	return cur;
}
string s[N];
bool solve(){
	cin >> n;
	for(int i=1; i<=sz ;i++) a[use[i]]=0;
	sz=0;
	for(int i=1; i<=n ;i++) cin >> s[i];
	for(int i=1; i<=n ;i++){
		auto t=s[i];reverse(t.begin(),t.end());
		{
			for(char c='a'; c<='z' ;c++){
				string u=t+c;
				if(a[en(u)]) return true;
			}
		}
		if(s[i]==t) return true;
		if(a[en(t)]) return true;
		int x=en(s[i]);
		a[x]=1;
		use[++sz]=x;
		
	}
	for(int i=1; i<=sz ;i++) a[use[i]]=0;
	sz=0;
	for(int i=1; i<=n ;i++){
		reverse(s[i].begin(),s[i].end());
	}
	reverse(s+1,s+n+1);
	for(int i=1; i<=n ;i++){
		auto t=s[i];reverse(t.begin(),t.end());
		{
			for(char c='a'; c<='z' ;c++){
				string u=t+c;
				if(a[en(u)]) return true;
			}
		}
		if(s[i]==t) return true;
		if(a[en(t)]) return true;
		int x=en(s[i]);
		a[x]=1;
		use[++sz]=x;
		
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
	int t;cin >> t;
	while(t--){
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}