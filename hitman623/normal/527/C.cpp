#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int w,y,n;
set<int> h,v;
multiset<int> hf,vf;
void solve(){
    cin>>w>>y>>n;
    h.insert(0);
    h.insert(w);
    v.insert(0);
    v.insert(y);
    hf.insert(w);
    vf.insert(y);
    while(n--){
        char c;
        int x;
        cin>>c>>x;
        if(c=='V'){
            h.insert(x);
            auto it=h.find(x);
            int l=*(--it);
            ++it,++it;
            int r=*it;
            hf.erase(hf.find(r-l));
            hf.insert(r-x);
            hf.insert(x-l);
            cout<<(*hf.rbegin())*(*vf.rbegin())<<endl;
        }
        else{
            v.insert(x);
            auto it=v.find(x);
            int l=*(--it);
            ++it,++it;
            int r=*it;
            vf.erase(vf.find(r-l));
            vf.insert(r-x);
            vf.insert(x-l);
            cout<<(*hf.rbegin())*(*vf.rbegin())<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}