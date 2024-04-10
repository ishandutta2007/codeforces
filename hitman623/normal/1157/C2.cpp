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
int n,a[200005];
string res;
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    int l=0,r=n-1,last=0;
    while(l<=r and a[l]!=a[r]){
        if(a[l]>last and a[r]>last){
            if(a[l]<a[r]){
                res+='L';
                last=a[l];
                l++;
            }
            else{
                res+='R';
                last=a[r];
                r--;
            }
        }
        else if(a[l]>last){
            res+='L';
            last=a[l];
            l++;
        }
        else if(a[r]>last){            
            res+='R';
            last=a[r];
            r--;
        }
        else break;
    }
    if(l<=r and (a[l]>last or a[r]>last)){
        string res1=res;
        string res2=res;
        int cur=l;
        rep(i,l+1,r+1){
            if(a[i-1]>=a[i]){
                cur=i-1;
                break;
            }
        }
        rep(i,l,cur+1) res1+='L';
        cur=r;
        for(int i=r-1;i>=l;i--){
            if(a[i]<=a[i+1]){
                cur=i+1;
                break;
            }
        }
        rep(i,cur,r+1){
            res2+='R';
        }
        if(sz(res1)>sz(res2)) res=res1;
        else res=res2;
    }
    cout<<sz(res)<<endl;
    cout<<res<<endl;
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