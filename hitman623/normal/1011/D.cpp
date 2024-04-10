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
int m,n,a[33],x,y,cur;
int query(int w){
    cout<<w<<endl;
    fflush(stdout);
    cin>>w;
    fflush(stdin);
    return w;
}
bool check(int mid){
    int d=query(mid);
    if(d==0) exit(0);
    if(a[cur]==1){
        if(d==1){
            return 0;
        }
        else return 1;
    }
    else{
        if(d==1){
            return 1;
        }
        else{
            return 0;
        }
    }
}
void solve(){
    cin>>m>>n;
    fflush(stdin);
    rep(i,0,n){
        int g=query(1);
        if(g==1) a[i]=1;
        else if(g==-1) a[i]=0;
        else exit(0);
    }
    int lo=1,hi=m+1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid;
        }
        else lo=mid;
        cur++;
        cur%=n;
    }
    if(query(lo)==0) exit(0);
    if(query(hi)==0) exit(0);
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}