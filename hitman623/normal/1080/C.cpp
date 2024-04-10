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
int b(int n,int m,int c){
    if(n<0 or m<0) return 0;
    if(c==0){
        return (n*m)/2;
    }
    else return (n*m+1)/2;
}
int w(int n,int m,int c){
    if(n<0 or m<0) return 0;
    if(c==0){
        return (n*m+1)/2;
    }
    else return (n*m)/2;
}
void solve(){
    int n,m,x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;    
    cin>>x3>>y3>>x4>>y4;    
    int black=b(n,m,0),white=w(n,m,0);
    int lx=max(x1,x3),rx=min(x2,x4);
    int ly=max(y1,y3),ry=min(y2,y4);
    black-=b(x2-x1+1,y2-y1+1,(x1+y1)%2)-b(rx-lx+1,ry-ly+1,(lx+ly)%2);
    black+=w(x4-x3+1,y4-y3+1,(x3+y3)%2);
    white+=b(x2-x1+1,y2-y1+1,(x1+y1)%2)-b(rx-lx+1,ry-ly+1,(lx+ly)%2);
    white-=w(x4-x3+1,y4-y3+1,(x3+y3)%2);
    cout<<white<<" "<<black<<endl;
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