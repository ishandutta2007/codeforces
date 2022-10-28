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
    int n,k;
	cin>>n>>k;
	vector<int> ans;
	vector<pair<int,int>> segment[200005];
	set<pair<int,int>> insidesegment;
	for(int i=0;i<n;i++){
	  int l,r;
	  cin>>l>>r;
	  segment[l].pb(mp(r,i)); 
	}
	
    for(int i=0;i<200003;i++){
        for(int j=0;j<segment[i].size();j++){
            insidesegment.insert(segment[i][j]);
        }
        set<pair<int,int>> :: iterator itr;
        insidesegment.erase(insidesegment.begin(),insidesegment.lower_bound(mp(i,-1)));
        while(insidesegment.size()>k){
            ans.pb((*prev(insidesegment.end())).second);
            insidesegment.erase(prev(insidesegment.end()));
        }
        
    }
    cout<<ans.size();
    cout<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<'\n';
}