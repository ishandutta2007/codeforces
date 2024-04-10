#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll n) {
    vector<int> base3;
    while(n>0) {
        base3.push_back(n%3);
        n/=3;
    }
    int i=base3.size()-1; while(base3[i]!=2) {i--; if(i<0) break;}
    for(int j=i; j>=0; j--) base3[j]=0;
    bool c=0;
    if(i>=0) {i++; if(i>=base3.size()) {base3.push_back(1); c=1;} if(c==0) while(base3[i]==1) {base3[i]=0; i++; if(i>=base3.size()) {base3.push_back(1); c=1; break;}} if(c==0)base3[i]=1; }
    ll k=1, ans=0; for(int i=0; i<base3.size(); i++) {
        ans+=base3[i]*k; k*=3;
    }
    return ans;
}

int32_t main(){
    int q; cin>>q; while(q--) {
        ll n; cin>>n; cout<<f(n)<<endl;
    }

}