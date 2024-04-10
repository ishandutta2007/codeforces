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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll n;
string str;
int main(){
    cin>>n;
	if(n%2 == 0){
		cout << n/2 << endl;
	}
	else{
		for(ll i=2;i*i<=n;i++){
			if(n%i == 0){
				n -= i;
				cout << 1+n/2 << endl;
				return 0;
			}
		}
		// n is prime
		cout << 1 << endl;
	}
}