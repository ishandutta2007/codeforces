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
int a,b,ans=LLONG_MAX,diva[1000006],divb[1000006],cnta,cntb;
void solve(){
    cin>>a>>b;
    for(int i=1;i*i<=a;++i){
        if(a%i) continue;
        diva[cnta++]=i;
        if(i!=a/i){
            diva[cnta++]=a/i;
        }
    }
    for(int i=1;i*i<=b;++i){
        if(b%i) continue;
        divb[cntb++]=i;
        if(i!=b/i){
            divb[cntb++]=b/i;
        }
    }
    sort(diva,diva+cnta);
    sort(divb,divb+cntb);
    for(int i=1;i*i<=(a+b);++i){
        if((a+b)%i) continue;
        int rows=i,cols=(a+b)/i;
        if(b%rows==0 and a%rows==0){
            ans=min(ans,2*rows+2*cols);
            continue;
        }
        if(b%cols==0 and a%cols==0){
            ans=min(ans,2*rows+2*cols);
            continue;
        }
        int l=upper_bound(diva,diva+cnta,cols)-diva-1;
        if(l>=0 and a/diva[l]<=rows){
            ans=min(ans,2*rows+2*cols);
            continue;
        }
        l=upper_bound(diva,diva+cnta,rows)-diva-1;
        if(l>=0 and a/diva[l]<=cols){
            ans=min(ans,2*rows+2*cols);
            continue;
        }
        l=upper_bound(divb,divb+cntb,cols)-divb-1;
        if(l>=0 and b/divb[l]<=rows){
            ans=min(ans,2*rows+2*cols);
            continue;
        }
        l=upper_bound(divb,divb+cntb,rows)-divb-1;
        if(l>=0 and b/divb[l]<=cols){
            ans=min(ans,2*rows+2*cols);
            continue;
        }
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