#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi             map<int,int>
#define mii            map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
int n,k,ans[1000006],sparse1[22][1000006],sparse2[22][1000006];
vi v(1000006),c(1000006);
void preprocess(){
    rep(i,0,22){
        rep(j,0,n){
            if(i==0){
                sparse1[i][j]=v[j];
                sparse2[i][j]=c[j];
            }
            else{
                sparse1[i][j]=max(sparse1[i-1][j],sparse1[i-1][min(n-1,j+(1<<(i-1)))]);
                sparse2[i][j]=min(sparse2[i-1][j],sparse2[i-1][min(n-1,j+(1<<(i-1)))]);   
            }
        }
    }
}
int query(int x,int y){
    y=min(y,n-1);
    int d=log2(y-x+1);
    return max(sparse1[d][x],sparse1[d][y-(1<<d)+1])<min(sparse2[d][x],sparse2[d][y-(1<<d)+1]);
}
int query2(int x,int y){
    y=min(y,n-1);
    int d=log2(y-x+1);
    return min(max(sparse1[d][x],sparse1[d][y-(1<<d)+1]),min(sparse2[d][x],sparse2[d][y-(1<<d)+1]));
}
void solve()
{
    cin>>n>>k;
    rep(i,0,n){
        cin>>v[i];
        v[i]*=100;
    }
    rep(i,0,n){
        cin>>c[i];
    }
    preprocess();
    rep(i,0,n){
        int lo=i,hi=n;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(query(i,mid)) lo=mid;
            else hi=mid;
        }
        ans[i]=max(query2(i,lo),query2(i,lo+1));
    }
    cout<<fixed<<setprecision(10);
    sort(ans,ans+n);
    long double finalans=0,p=1.0*k/n;
    finalans=p*ans[0];
    rep(i,1,n){
        p=p*(n-i-k+1)/(n-i);
        finalans+=p*ans[i];
    }
    cout<<finalans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}