/**
 *    author:  gary
 *    created: 08.09.2021 22:32:56
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
int n,a[55];
char ans[55][55];
void solve(){
    cin>>n;
    rb(i,1,n){
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    int cnt=0;
    rb(i,1,n) cnt+=a[i]==2;
    if(cnt<=2&&cnt){
        puts("NO");
    }
    else{
        puts("YES");
        vector<int> g;
        rb(i,1,n) rb(j,1,n){
            if(i==j) ans[i][j]='X';
            else ans[i][j]='=';
        }
        rb(i,1,n) if(a[i]==2) g.PB(i);
        if(g.size()) g.PB(g[0]);
        rep(i,g.size()){
            if(i!=g.size()-1){
                ans[g[i]][g[i+1]]='+';
                ans[g[i+1]][g[i]]='-';
            }
        }
        rb(i,1,n){
            rb(j,1,n){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}