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
int n,a[12001],s1,s2;
void print(){
    rep(_,0,2*n){
        cout<<a[_]<<" ";
    }
    cout<<endl;
}
void solve(){
    cin>>n;
    rep(i,0,2*n){
        cin>>a[i];
        if(i<n) s1+=a[i];
        else s2+=a[i];
    }
    if(s1==s2){
        rep(i,0,n){
            rep(j,n,2*n){
                if(a[i]!=a[j]){
                    swap(a[i],a[j]);
                    print();
                    return;
                }
            }
        }
    }
    else{
        print();
        return;
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