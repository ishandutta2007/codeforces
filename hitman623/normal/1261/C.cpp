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
int n,m;
string s[1000006];
vector<vi> a,b,c;
int get(int x,int y,int w){
    if(x+w<n and y+w<m and x-w>=0 and y-w>=0){
        int d=a[x+w][y+w]-(x-w-1>=0?a[x-w-1][y+w]:0)-(y-w-1>=0?a[x+w][y-w-1]:0)+((x-w-1>=0 and y-w-1>=0)?a[x-w-1][y-w-1]:0);
        return d==(2*w+1)*(2*w+1);
    }
    else return 0;
}
void upd(int x,int y,int w){
    c[x+w][y+w]+=1;
    if(x-w-1>=0) c[x-w-1][y+w]-=1;
    if(y-w-1>=0) c[x+w][y-w-1]-=1;
    if(x-w-1>=0 and y-w-1>=0) c[x-w-1][y-w-1]+=1;
}
int query(int t){
    rep(i,0,n){
        rep(j,0,m){
            c[i][j]=b[i][j]=0;
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(get(i,j,t)){
                b[i][j]=1;
                upd(i,j,t);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            c[i][j]+=(i+1<n?c[i+1][j]:0)+(j+1<m?c[i][j+1]:0)-((i+1<n and j+1<m)?c[i+1][j+1]:0);
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='X' and c[i][j]==0) return 0;
            if(s[i][j]=='.' and c[i][j]) return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    rep(i,0,n){
        a[i].resize(m);
        b[i].resize(m);
        c[i].resize(m);
    }
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        rep(j,0,m){
            a[i][j]=(s[i][j]=='X')+(i?a[i-1][j]:0)+(j?a[i][j-1]:0)-((i and j)?a[i-1][j-1]:0);
        }
    }
    int lo=0,hi=n+m+1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(query(mid)) lo=mid;
        else hi=mid;
    }
    cout<<lo<<endl;
    query(lo);
    rep(i,0,n){
        rep(j,0,m){
            if(b[i][j]) cout<<'X';
            else cout<<'.';
        }
        cout<<endl;
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