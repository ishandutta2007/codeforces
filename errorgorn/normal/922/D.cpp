#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,string> ii;
int n;
string s;
string t;
vector<ii> v;
int main(){
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>s;
        int ss=0;
        for (int y=0;y<s.size();y++) if (s[y]=='s') ss++;
        v.push_back(ii(ss,s));
    }
    
    sort(v.begin(),v.end(),[](ii i, ii j){
        return i.first*j.second.size()>j.first*i.second.size();
    });
    
    for (int x=0;x<n;x++) t+=v[x].second;
    
    long long ans=0;
    int curr=0;
    for (int x=0;x<t.size();x++){
        if (t[x]=='s') curr++;
        else ans+=curr;
    }
    
    cout<<ans;
}