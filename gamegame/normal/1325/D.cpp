#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
int n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	ll x,y;
	cin >> x >> y;
	if(x==0 && y==0){
		cout << "0\n";
		return 0;
	}
	if(x%2!=y%2) return cout << "-1\n",0;
	if(x>y) return cout << "-1\n",0;
	if(x==y) return cout << "1\n" << x << '\n',0;
	ll z=(y-x)/2;
	if((x^z)==(x+z)) return cout << "2\n" << x+z << ' ' << z << '\n',0;
	else{
		cout << 3 << endl;
		cout << x << ' ' << z << ' ' << z << endl;
	}
}