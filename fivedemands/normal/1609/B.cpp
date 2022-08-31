#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,q;
char c[N];
int cnt=0;
void upd(int p,int v){
	if(p>n-2 || p<=0) return;
	if(c[p]=='a' && c[p+1]=='b' && c[p+2]=='c') cnt+=v;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q;
	for(int i=1; i<=n ;i++){
		cin >> c[i];
	}
	for(int i=1; i<=n-2 ;i++) upd(i,1);
	for(int i=1; i<=q ;i++){
		int p;char b;
		cin >> p >> b;
		for(int j=p-2; j<=p ;j++) upd(j,-1);
		c[p]=b;
		for(int j=p-2; j<=p ;j++) upd(j,1);
		cout << cnt << '\n';
	}
}