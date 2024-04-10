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
int n,a[100005],pos[100005];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        pos[a[i]]=i;
    }
    int last=n;
    rep(i,1,n+1){
        int cur=i,p=pos[i];
        while(p<=last and pos[cur]==p) cur++,p++;
        if(p!=last+1){
            cout<<"No"<<endl;
            return;
        }
        last=pos[i]-1;
        i=cur-1;
    }
    cout<<"Yes"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}