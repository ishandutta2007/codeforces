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
	    int n,m,x,y;
	    cin>>n>>m>>x>>y;
	    int ans=0;
	    ans=max(n-x-1,x)*m;
	    ans=max(max(m-y-1,y)*n,ans);
	    cout<<ans<<'\n';
	    
	    
	}
	
}