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
string a,b;
int cnt1,cnt2,ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>a>>b;
	for(auto &it : b) if(it=='1') cnt2++;
	for(int i=0;i<b.size();i++) if(a[i]=='1') cnt1++;
	if(cnt1%2==cnt2%2) ans++;
	for(int i=b.size();i<a.size();i++){
		if(a[i-b.size()]=='1') cnt1--;
		if(a[i]=='1') cnt1++;
		if(cnt1%2==cnt2%2) ans++;
	}
	cout<<ans;
    return 0;
}