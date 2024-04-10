#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
long long int p=1e9 +7;
long long int modpower(long long int b,long long po){
    long long int ans=1;
    while(po){
        if(po%2){
            ans*=b;
            ans%=p;
        }
        b*=b;
        b%=p;
        po/=2;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >>t;
	while(t--){
	    ll n,ans;
	    ll removable=0;
	    cin>>n;
	    ans=n;
	    ll s=1;
	    while(n){
	        if(n%3==2){
	            ans+=s;
	            n+=1;
	            ans-=removable;
	            removable=0;
	        }
	        removable+=s*(n%3);
	        n/=3;
	        s*=3;
	    }
	    cout<<ans<<"\n";
	    
	    
	}
	
}