#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll,ll> P;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
const int N=2005;
const ll mod=998244853;
int n,m;
string s[N];
ll cnt[N][5],a[N],ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=m;j++){
			cnt[j][s[i][j-1]-'A']++;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
		ll cur=0;
		for(int j=0;j<5;j++) cur=max(cur,cnt[i][j]);
		ans+=cur*a[i];
	}
	cout<<ans;
    return 0;
}