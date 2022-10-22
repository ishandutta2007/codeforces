/**
 *    author:  gary
 *    created: 07.10.2022 22:15:21
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
void solve(){
    int n;
    cin>>n;
    int r1,c1,r2,c2,r3,c3;
    cin>>r1>>c1>>r2>>c2>>r3>>c3;
    int R,C;
    R=r1+r2+r3-min(min(r1,r2),r3)-max(max(r1,r2),r3);
    C=c1+c2+c3-min(min(c1,c2),c3)-max(max(c1,c2),c3);
    int a[2][2];
    memset(a,0,sizeof(a));
    a[r1&1][c1&1]=1;
    a[r2&1][c2&1]=1;
    a[r3&1][c3&1]=1;
    int x,y;
    cin>>x>>y;
    if(R==1&&C==1){
        a[x&1][y&1]=(x==1||y==1);
    }
    if(R==1&&C==n){
        a[x&1][y&1]=(x==1||y==n);
    }
    if(R==n&&C==1){
        a[x&1][y&1]=(x==n||y==1);
    }
    if(R==n&&C==n){
        a[x&1][y&1]=(x==n||y==n);
    }
    cout<<(a[x&1][y&1]? "YES":"NO")<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}