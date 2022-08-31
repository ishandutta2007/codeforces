#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define fi first
#define se second
const int N=2001;
const ll mod=998244353;
ll a[N],b[N];
int n,m;

//<edge>
//</groups>
bool can[1000];
bool isp[1000];
void solve(){
	string s;
	int n;cin >> n;
	cin >> s;
	for(int i=0; i<1000 ;i++) can[i]=false;
	can[0]=true;
	for(auto c:s){
		for(int j=99; j>=0 ;j--){
			if(can[j]) can[j*10+c-48]=true;
		}
	}
	for(int j=1; j<10 ;j++){
		if(can[j] && !isp[j]){
			cout << "1\n" << j << '\n';
			return;
		}
	}
	for(int j=10; j<100 ;j++){
		if(can[j] && !isp[j]){
			cout << "2\n" << j << '\n';
			return;
		}
	}
	for(int j=100; j<1000 ;j++){
		if(can[j] && !isp[j]){
			cout << "3\n" << j << '\n';
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	for(int i=2; i<1000 ;i++) isp[i]=true;
	for(int i=2; i<1000 ;i++){
		for(int j=2*i; j<1000 ;j+=i){
			isp[j]=false;
		}
	}
	int t;cin >> t;while(t--) solve();
}