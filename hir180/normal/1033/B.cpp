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
int t;
ll a,b;
int main(){
	cin>>t;
	rep(w,t){
		cin>>a>>b;
		ll c = a+b, d = a-b;
		if(d != 1){
			puts("NO");
		}
		else{
			bool ok = 1;
			for(ll x=2;x*x<=c;x++){
				if(c%x == 0){
					ok = 0;
					break;
				}
			}
			puts(ok?"YES":"NO");
		}
	}
}