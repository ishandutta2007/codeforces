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
	    int a,b,p;
	    string s;
	    cin>>a>>b>>p;
	    cin>>s;
	    int cost=0;
	    int dist=s.size();
	    reverse(s.begin(),s.end());
	    char prev=s[1];
	    for(int i=2;i<s.size();i++){
	        if(prev!=s[i]){
	            if(s[i]=='A'){
	                cost+=b;
	                if(cost>p){
	                    break;
	                }
	                dist=s.size()-i+1;
	            }
	            if(s[i]=='B'){
	                cost+=a;
	                if(cost>p){
	                    break;
	                }
	                dist=s.size()-i+1;
	            }
	        }
	        prev=s[i];
	    }
	    if(s[s.size()-1]=='A'){
	        if(cost+a<=p){
	            dist=1;
	        }
	    }
	    else{
	        if(cost+b<=p){
	            dist=1;
	        }
	    }
	    cout<<dist<<'\n';
	}
	
}