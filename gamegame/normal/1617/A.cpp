#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
bool cmp(char c,char d){
	if(c=='b' && d=='c') return false;
	else if(c=='c' && d=='b') return true;
	else return c<d;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		string p,q;
		cin >> p >> q;
		if(q=="abc"){
			sort(p.begin(),p.end(),cmp);
			if(p[0]!='a') sort(p.begin(),p.end());
		}
		else{
			sort(p.begin(),p.end());
		}
		cout << p << '\n';
	}
}