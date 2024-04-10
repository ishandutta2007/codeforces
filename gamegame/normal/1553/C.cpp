#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
string s,t;
int n,m;
void solve(){
	cin >> s;
	int t1=0,w1=5,t2=0,w2=5;
	int ans=10;
	for(int i=0; i<10 ;i++){
		if(i%2==0){
			t1+=(s[i]!='0');
			w1--;
		}
		else{
			t2+=(s[i]=='1');
			w2--;
		}
		if(t1+w1<t2 || t2+w2<t1){
			ans=min(ans,i+1);break;
		}
	}
	t1=0,w1=5,t2=0,w2=5;
	for(int i=0; i<10 ;i++){
		if(i%2==0){
			t1+=(s[i]=='1');
			w1--;
		}
		else{
			t2+=(s[i]!='0');
			w2--;
		}
		if(t1+w1<t2 || t2+w2<t1){
			ans=min(ans,i+1);break;
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}