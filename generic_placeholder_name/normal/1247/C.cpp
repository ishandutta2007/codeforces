#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll n, ll k){
	if (n<=0) return 0;
	ll a[k]; for(int i=0; i<k; i++) a[i]=1; ll sum=k;
	for (int i=k-1; i>=0; i--) {
        while (sum+a[i]<=n) {
            sum+=a[i]; a[i]*=2;
        }
    }
    return sum==n;
}

int32_t main(){
    ll n, p; cin>>n>>p;
    for (int i=0; i<65; i++){
    	ll curr=n-(i*p);
    	if (check(curr, i)){
            cout<<i<<endl; return 0;
		}
	}
	cout<<-1<<endl;
    return 0;
}