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
#define N           500005
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int m,k,n,s,a[N],b[N];
int freq[N],req[N],cnt,cntreqd;
void add(int x){
    freq[x]++;
    if(freq[x]==req[x]) cnt++;
}
void rem(int x){
    if(freq[x]==req[x]) cnt--;
    freq[x]--;
}
void solve(){
    cin>>m>>k>>n>>s;
    rep(i,1,m+1) cin>>a[i];
    rep(i,1,s+1){
        cin>>b[i];
        req[b[i]]++;
        if(req[b[i]]==1) cntreqd++;
    }
    int cur=1;
    rep(i,1,m+1){
        while(cnt!=cntreqd and cur<=m) add(a[cur++]);
        if(cnt==cntreqd){
            // i,cur-1
            int l=cur-i;
            int remleft=(i-1)%k;
            int remright=max(0,l-k);
            if(m-remleft-remright>=n*k){
                cout<<remleft+remright<<endl;
                rep(j,0,remleft) cout<<j+1<<" ";
                rep(j,i,cur){
                    if(remright==0) break;
                    rem(a[j]);
                    if(cnt!=cntreqd) add(a[j]);
                    else{
                        remright--;
                        cout<<j<<" ";
                    }
                }
                cout<<endl;
                return;
            }
        }
        rem(a[i]);
    }
    cout<<-1<<endl;
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