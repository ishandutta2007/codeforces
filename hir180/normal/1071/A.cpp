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
ll a,b,c;
vector<ll>A,B;
int main(){
	cin>>a>>b;
	for(ll i=1;;i++){
		if(i*(i+1)/2 > a+b){
			c = i-1;
			break;
		}
	}
	for(ll i=c;i>=1;i--){
		if(a >= i){
			A.pb(i);
			a -= i;
		}
		else{
			B.pb(i);
			b -= i;
		}
	}
	cout << A.size() << endl;
	rep(i,A.size()) cout << A[i] << " "; cout << endl;
	cout << B.size() << endl;
	rep(i,B.size()) cout << B[i] << " "; cout << endl;

}