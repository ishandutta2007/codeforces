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
	    int n;
	    cin>>n;
	    bool poss=1;
	    bool used[2*n + 6]={0};
	    pair<int,int> a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i].first;
	        used[a[i].first]=1;
	    }
	    for(int i=0;i<n;i++){
	        int k=1;
	        while(a[i].first+k<=2*n && used[a[i].first+k]){
	        k++;
	        }
	        if(a[i].first+k<=2*n){
	            used[a[i].first+k]=1;
	        a[i].second=a[i].first+k;
	        }
	        else{
	            poss=0;
	            break;
	        }
	    }
	    if(poss){
	    for(int i=0;i<n;i++){
	        cout<<a[i].first<<" "<<a[i].second<<" ";
	    }
	    }
	    else{
	        cout<<"-1";
	    }
	    cout<<"\n";
	}
	
}