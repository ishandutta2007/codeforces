#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll,ll> P;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
const int N=1e5+5;
const ll mod=998244853;
int n;
ll a[N],mx,s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		s+=a[i];
	}
	if(s&1||mx>s/2){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
    return 0;
}