#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
//typedef tuple<int,int,int> TP;
typedef tuple<int,int,int,int> TP;
const int N=1e5+5,M=1e6+5;
const ll MOD=1e9+7;
int n,m,cur,a[N],e[N],pos;
string s[N];
map<P,vector<string>> mp;
vector<string> se,de[M],ans;
// se : 2  de : 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++) if(s[i][j]=='a'||s[i][j]=='e'||s[i][j]=='i'||s[i][j]=='o'||s[i][j]=='u'){
            a[i]++;
            e[i]=s[i][j]-25;
        }
        mp[P(a[i],e[i])].push_back(s[i]);
    }
    for(auto &it : mp){
        P tp=it.fi;
        int d=tp.fi;
        pos+=it.se.size()/2;
        int sz=it.se.size()/2*2;
        for(int i=0;i<sz;i++) se.push_back(it.se[i]);
        for(int i=sz;i<it.se.size();i++) de[d].push_back(it.se[i]);
    }
    for(int i=1;i<=1e6;i++){
        if(cur==se.size()) break;
        for(int j=0;j+1<de[i].size();j+=2){
            ans.push_back(de[i][j]); ans.push_back(se[cur++]);
            ans.push_back(de[i][j+1]); ans.push_back(se[cur++]);
        }
    }
    for(;cur+3<se.size();cur+=4){
         ans.push_back(se[cur]); ans.push_back(se[cur+2]);
         ans.push_back(se[cur+1]); ans.push_back(se[cur+3]);
    }
    cout<<ans.size()/4<<"\n";
    for(int i=0;i<ans.size();i+=2) cout<<ans[i]<<" "<<ans[i+1]<<"\n";
    return 0;
}