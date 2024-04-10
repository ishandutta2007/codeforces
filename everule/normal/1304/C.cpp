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
	    ll n,mintemp,maxtemp;
	    cin>>n>>mintemp;
	    bool poss=1;
	    maxtemp=mintemp;
	    ll ct=0;
	    for(int i=0;i<n;i++){
	        ll t,l,r;
	        cin>>t>>l>>r;
	        if(l>maxtemp+t-ct){
	            poss=0;
	        }
	        if(r<mintemp-t+ct){
	            poss=0;
	        }
	        maxtemp=min(r,maxtemp+t-ct);
	        mintemp=max(l,mintemp-t+ct);
	        ct=t;
	    }
	    if(poss){
	        cout<<"YES";
	    }
	    else{
	        cout<<"NO";
	    }
	    cout<<"\n";
	}
	
}