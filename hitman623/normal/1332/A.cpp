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
int a,b,c,d,x,y,x1,yy1,x2,yy2;
void solve(){
    cin>>a>>b>>c>>d>>x>>y>>x1>>yy1>>x2>>yy2;
    if(x1<=x-a+b and x-a+b<=x2 and yy1<=y-c+d and y-c+d<=yy2){
        if(a==b and a and x1==x2) cout<<"No"<<endl;
        else if(c==d and c and yy1==yy2) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
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