#include <bits/stdc++.h>
#define fi first
#define se second
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll,ll> P;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> TP;
const int N=2e5+5;
const ll mod=1e9+7;
int n,a[N];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	if(n%2==0){
		cout<<"NO";
		return 0;
	}
	for(int i=1,c=1;;i-=2,c+=2){
		if(i<=0) i+=2*n;
		if(a[i]) break;
		a[i]=c;
	}
	for(int i=n+1,c=2;;i-=2,c+=2){
		if(i<=0) i+=2*n;
		if(a[i]) break;
		a[i]=c;
	}
	cout<<"YES\n";
	for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
    return 0;
}