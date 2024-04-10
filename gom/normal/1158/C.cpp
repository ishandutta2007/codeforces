#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> PP;
const int N=5e5+5;
const ll MOD=1e9+7;
int n,cnt,nxt[N],a[N],deg[N],fr[N];
vector<int> g[N];
void solve()
{
    cin>>n; cnt=0;
    queue<int> que;
    set<int> st;
    for(int i=1;i<=n;i++){
        a[i]=fr[i]=deg[i]=0;
        g[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin>>nxt[i];
    }
    for(int i=n;i>=1;i--){
        if(nxt[i]!=-1) cnt++;
        while(st.size()){
            auto it=st.begin();
            if((*it)>=nxt[i]) break;
            g[i].push_back(*it);
            deg[*it]++;
            //cout<<i<<"-->"<<(*it)<<endl;
            st.erase(it); it++;
        }
        st.insert(i);
        if(nxt[i]!=n+1&&nxt[i]!=-1){
            g[nxt[i]].push_back(i);
            //cout<<nxt[i]<<"->"<<i<<endl;
            deg[i]++;
        }
    }
    if(!cnt){
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==0) que.push(i);
    }
    cnt=n+1;
    while(que.size()){
        int tp=que.front(); que.pop();
        a[tp]=--cnt;
        for(auto &it : g[tp]){
            deg[it]--;
            if(deg[it]==0) que.push(it);
        }
    }
    for(int i=1;i<=n;i++){
        if(!a[i]){
            cout<<"-1\n";
            return;
        }
        fr[a[i]]=i;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) solve();
    return 0;
}