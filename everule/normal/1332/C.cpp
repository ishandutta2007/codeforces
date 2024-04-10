#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
int maxcount(const vector<char>& seq){
    int count=1,ans=1;
    for(int i=1;i<seq.size();i++){
        if(seq[i]!=seq[i-1]){
            ans=max(ans,count);
            count=1;
            continue;
        }
        count++;
    }
    ans=max(ans,count);
    return ans;
}
ll solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    if(k==1){
        map<int,int> a;
        for(int i=0;i<n;i++){
            a[s[i]- '0']++;
        }
        for(auto g : a){
            ans=max(ans,g.second);
        }
        return n-ans;
    }
    for(int i=0;i<k/2;i++){
        vector<char> seq(2*n / k);
        int idx=0;
        for(int j=i;j<n;j+=k){
            seq[idx++]=s[j];
            //cout<<j<<" ";
        }
        for(int j=n-1-i;j>=0;j-=k){
            seq[idx++]=s[j];
            //cout<<j<<" ";
        }
        sort(seq.begin(),seq.end());
        ans+= (2*n)/k - maxcount(seq);
        //cout<<"\n";
    }
    //cout<<ans<<"\n";
    if(k%2){
        vector<char> seq(n/k);
        int idx=0;
        for(int i=k/2;i<n;i+=k){
            seq[idx++]=s[i];
        }
        sort(seq.begin(),seq.end());
        ans+= n/k - maxcount(seq);
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    //precompute();
    while(t--){
        //init();
        cout<<solve()<<"\n";
    }
}