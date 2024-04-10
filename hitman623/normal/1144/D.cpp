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
int n,f[200005],mx=0,pos=-1,val=-1,a[200005];
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        a[i]=x;
        f[x]++;
        if(f[x]>mx){
            mx=f[x];
            val=x;
            pos=i;
        }
    }
    cout<<n-mx<<endl;
    rep(i,pos+1,n){
        if(a[i]>val){
            cout<<2<<" "<<i+1<<" "<<i<<endl;
        }
        else if(a[i]<val){
            cout<<1<<" "<<i+1<<" "<<i<<endl;
        }
        a[i]=val;
    }
    for(int i=pos-1;i>=0;i--){
        if(a[i]>val){
            cout<<2<<" "<<i+1<<" "<<i+2<<endl;
        }
        else if(a[i]<val){
            cout<<1<<" "<<i+1<<" "<<i+2<<endl;
        }
        a[i]=val;
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