/**
 *    author:  gary
 *    created: 22.01.2022 22:10:12
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int a[1001][1001];
void solve(){
    int n;
    cin>>n;
    rb(i,1,n) rb(j,1,n) cin>>a[i][j];
    int sum=0;
    int pre=0;
    for(int i=1;i<=n;i+=2){
        int x,y;
        x=1;
        y=i;
        int now=0;
        while(true){
            now^=a[x][y];
            if(y==1||x==n) break;
            x+=2;
            y-=2;
        }
        sum^=now^pre;
        pre=now^pre;
        // cout<<i<<" "<<pre<<endl;
    }
    for(int i=2;i<=n;i+=2){
        int x,y;
        x=i;
        y=n;
        int now=0;
        while(true){
            now^=a[x][y];
            if(y==1||x==n) break;
            x+=2;
            y-=2;
        }
        sum^=now^pre;
        pre=now^pre;
    }
    pre=0;
    for(int i=n;i>=1;i-=2){
        int x,y;
        x=1;
        y=i;
        int now=0;
        while(true){
            now^=a[x][y];
            if(y==n||x==n) break;
            x+=2;
            y+=2;
        }
        sum^=now^pre;
        pre=now^pre;
    }
    for(int i=2;i<=n;i+=2){
        int x,y;
        x=i;
        y=1;
        int now=0;
        while(true){
            now^=a[x][y];
            if(y==n||x==n) break;
            x+=2;
            y+=2;
        }
        sum^=now^pre;
        pre=now^pre;
    }
    cout<<sum<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}