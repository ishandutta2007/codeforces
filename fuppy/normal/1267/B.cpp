#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)

main(){
    string s;cin>> s;
    int now=1;
    vector<pair<char,int>> v;
    rep(i,s.size()){
        while(i<s.size()&&s[i]==s[i+1]){
            i++;now++;
        }
        v.push_back({s[i],now});
        now=1;
    }
    if(v.size()%2==0)cout<<0<<endl;
    else{
        bool flag=true;
        int sz=v.size();
        rep(i,sz/2){
            flag&=(v[i].first==v[sz-1-i].first)&&(v[i].second+v[sz-i-1].second>=3); 
        }
        flag&=(v[sz/2].second>1);
        cout<< (flag? v[sz/2].second+1 : 0)<<endl;
    }
}