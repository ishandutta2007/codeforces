#include <bits/stdc++.h>

#define ll          long long
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
int n,k,a[200005];
ll ans;
string s;
char last;
multiset<int> st;
void solve(){
    cin>>n>>k;
    rep(i,0,n) cin>>a[i];
    cin>>s;
    st.insert(a[0]);
    last=s[0];
    rep(i,1,sz(s)){
        if(s[i]==last){
            st.insert(a[i]);
        }
        else{
            int cnt=k;
            auto d=--st.end();
            while(cnt){
                cnt--;
                ans+=*d;
                if(d==st.begin()) break;
                d--;
            }
            st.clear();
            last=s[i];
            st.insert(a[i]);
        }
    }
    int cnt=k;
    auto d=--st.end();
    while(cnt){
        cnt--;
        ans+=*d;
        if(d==st.begin()) break;
        d--;
    }
    cout<<ans<<endl;
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