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
int n,a[505][505];
void solve(){
    cin>>n;
    if(n<=2){
        cout<<-1<<endl;
        return;
    }
    if(n==3){
        cout<<"9 4 7"<<endl;
        cout<<"5 6 8"<<endl;
        cout<<"1 3 2"<<endl;
        return;
    }
    int m=n*n;
    a[1][1]=m--;
    a[2][3]=m--;
    a[1][3]=m--;
    a[2][2]=m--;
    a[2][1]=m--;
    a[1][2]=m--;
    m=1;
    for(int i=n-1;i>=4;i--) a[1][i]=m++;
    for(int i=4;i<=n-1;i++) a[2][i]=m++;
    rep(i,3,n+1){
        if(i%2) for(int j=n-1;j>=1;j--) a[i][j]=m++;
        else for(int j=1;j<=n-1;j++) a[i][j]=m++;
    }
    for(int i=n;i>=1;i--) a[i][n]=m++;
    rep(i,1,n+1){
        rep(j,1,n+1){
            cout<<a[i][j]<<" ";
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