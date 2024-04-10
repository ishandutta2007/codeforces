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
int n,t,a[200005],x[200005],b[200005];
void solve(){
    cin>>n>>t;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>x[i];
        if(x[i]<i+1 or (i and x[i]<x[i-1])){
            cout<<"No"<<endl;
            return;
        }
    }
    int last=0;
    rep(i,0,n){
        int j=i;
        while(j<n and x[j]==x[i]) j++;
        rep(k,i,j-1){
            b[k]=max(last+1,a[k+1]+t);
            last=b[k];
        }
        b[j-1]=max(last+1,a[j-1]+t);
        last=b[j-1];
        if(x[j-1]!=j or (i and a[i]+t<=b[i-1])){
            cout<<"No"<<endl;
            return;
        }
        i=j-1;
    }
    cout<<"Yes"<<endl;
    rep(i,0,n){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}