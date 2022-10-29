#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,d,day,ans[200005];
set<pii> st;
void solve(){
    cin>>n>>m>>d;
    rep(i,0,n){
        int x;
        cin>>x;
        st.insert({x,i});
    }
    while(!st.empty()){
        int cur=(*st.begin()).x;
        ans[(*st.begin()).y]=day;
        st.erase(st.begin());
        while(!st.empty()){
            pii temp={cur+d+1,-hell};
            auto it=st.lower_bound(temp);
            if(it!=st.end()){
                cur=(*it).x;
                ans[(*it).y]=day;
                st.erase(it);
            }
            else break;
        }
        day++;
    }
    cout<<day<<endl;
    rep(i,0,n) cout<<ans[i]+1<<" ";
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