#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
string s;
int n;
ll t;
ll f(char c){
	return (1<<(c-'a'));
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> t >> s;
	s='?'+s;
	if(n==1){
		if(t==f(s[0])) return cout << "Yes\n",0;
		else return cout << "No\n",0;
	}
	t-=f(s.back());s.pop_back();
	t+=f(s.back());s.pop_back();
	n-=2;
	for(int i=1; i<=n ;i++){
		t+=f(s[i]);
	}
	sort(s.begin()+1,s.end());
	for(int i=n; i>=1 ;i--){
		if(t>=2*f(s.back())) t-=2*f(s.back());
	}
	if(t==0) cout << "Yes\n";
	else cout << "No\n";
}