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
int n;
ll ans[N],s;
db arr[N],eps=1e-7;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		ans[i]=floor(arr[i]);
		s+=ans[i];
	}
	for(int i=1;i<=n;i++){
		if(s==0) break;
		if(arr[i]-eps<ans[i]&&arr[i]+eps>ans[i]) continue;
		ans[i]++; s++;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    return 0;
}