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
int cur=2,k,a[1001][1001],pre=1;
void solve(){
    cin>>k;
    while(k>1){
        if(k%2){
            int d=log2(k);
            d=2*d;
            int h=pre;
            rep(i,0,d){
                a[h][cur+1]=1;
                cur++;
                h=cur;
            }
            a[cur][2]=1;
        }
        a[pre][cur+1]=1;
        a[pre][cur+2]=1;
        a[cur+1][cur+3]=1;
        a[cur+2][cur+3]=1;
        pre=(cur+=3);
        k/=2;
    }
    a[pre][2]=1;
    cout<<cur<<endl;
    rep(i,1,cur+1){
        rep(j,1,cur+1){
            if(a[i][j] || a[j][i]) cout<<"Y";
            else cout<<"N";
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