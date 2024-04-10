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
const int N=2e5+5;
const ll mod=998244853;
int n,m,k;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k;
	if(m>=n&&k>=n) cout<<"Yes";
	else cout<<"No";
    return 0;
}