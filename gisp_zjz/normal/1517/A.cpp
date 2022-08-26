#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+100;
const int M=998244353;
ll x;
int main(){
	int _; cin >> _;
	while (_--){
		cin >> x;
		if (x%2050){
			puts("-1");continue;
		}
		x/=2050;
		int ans=0;
		while (x) ans+=x%10,x/=10;
		cout << ans << endl;
	}
}