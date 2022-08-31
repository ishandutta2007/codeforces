#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const ll N=2e6+1;
ll n,m;
char c[N];
vector<int>v;
char ax[N],ay[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> c[i];
	if(c[1]!='1' || c[n]!='1'){
		cout << "NO\n";return;
	}
	v.clear();
	for(int i=1; i<=n ;i++){
		if(c[i]=='1') v.push_back(i);
	}
	if(v.size()%2){
		cout << "NO\n";return;
	}
	for(int i=0; i<v.size() ;i++){
		if(i*2<v.size()) ax[v[i]]=ay[v[i]]='(';
		else ax[v[i]]=ay[v[i]]=')';
	}
	int lx=0,ly=0;
	int cnt=0;
	for(int i=1; i<=n ;i++){
		if(c[i]=='1'){
			if(ax[i]=='(') lx++,ly++;
			else lx--,ly--;
		}
		else{
			cnt++;
			if(cnt%2==1){
				ax[i]='(';ay[i]=')';
				lx++;ly--;
			}
			else{
				ax[i]=')';ay[i]='(';
				lx--;ly++;
			}
		}
		if(lx<0 || ly<0){
			cout << "NO\n";return;
		}
		
	}
	cout << "YES\n";
	for(int i=1; i<=n ;i++){
		cout << ax[i];
	}
	cout << '\n';
	for(int i=1; i<=n ;i++){
		cout << ay[i];
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}