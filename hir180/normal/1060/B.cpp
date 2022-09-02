#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll a;
map<ll,ll>M;
ll rec(ll n){
	if(M.find(n) != M.end()) return M[n];
	if(n <= 9) return M[n] = n;
	int dw = n%10;
	M[n] = 0;
	//dw
	M[n] = max(M[n],rec(n/10)+dw);
	//dw+10
	if(dw != 9 && n/10){
		M[n] = max(M[n],rec(n/10-1)+dw+10);
	}
	return M[n];
}
int main(){
	cin>>a;
	cout<<rec(a)<<endl;
}