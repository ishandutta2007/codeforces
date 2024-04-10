#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll,ll> P;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
const int N=2e5+5;
const ll mod=998244853;
int n;
ll k,a[N],l=1,r=2e9,ans=1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	while(l<=r){
		ll m=(l+r)/2,s=0;
		int plc=-1;
		for(int i=n;i>=1;i--) if(a[i]<m){
			plc=i;
			break;
		}
		if(plc<=n/2){
			ans=m;
			l=m+1;
			continue;
		}
		for(int i=plc;i>n/2;i--) s+=m-a[i];
		if(s<=k){
			ans=m;
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	cout<<ans;
    return 0;
}