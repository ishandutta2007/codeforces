#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const int N=1e7+5;
const ll mod=1e9+7;
ll t,a,b,n;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		if(n%3==0) cout<<a;
		else if(n%3==1) cout<<b;
		else cout<<(a^b);
		cout<<"\n";
	}
    return 0;
}