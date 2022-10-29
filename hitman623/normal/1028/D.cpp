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
int n,ans=1;
mi mark,accepted;
set<int> st;
vi added;
void solve(){
    cin>>n;
    rep(i,0,n){
        string s;
        cin>>s;
        if(s=="ADD"){
            int p;
            cin>>p;
            added.pb(p);
            st.insert(p);
            auto it=st.find(p);
            if(it!=st.begin()){
                it--;
                if(mark.count(*it) and mark[*it]==2){
                    mark[p]=2;
                }
                ++it;
            }
            ++it;
            if(it!=st.end()){
                if(mark.count(*it) and mark[*it]==1){
                    mark[p]=1;
                }
            }
        } 
        else{
            int p;
            cin>>p;
            auto it=st.find(p);
            accepted[p]=1;
            if(mark.count(p)==0){
                ans=(2LL*ans)%hell;
            }
            it++;
            while(it!=st.end()){
                if(mark.count(*it)){
                    if(mark[*it]!=2) ans=0;
                    break;
                }
                mark[*it]=2;
                it++;
            }
            it=st.find(p);
            if(it==st.begin()){
                st.erase(st.find(p));
                continue;
            }
            it--;
            while(1){
                if(mark.count(*it)){
                    if(mark[*it]!=1) ans=0;
                    break;
                }
                mark[*it]=1;
                if(it==st.begin()) break;
                it--;
            }
            st.erase(st.find(p));
        }
    }
    sort(all(added));
    int cnt=0;
    for(auto j:added) if(accepted.count(j)==0 and mark.count(j)==0) cnt++;
    ans=(1LL*ans*(cnt+1))%hell;
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