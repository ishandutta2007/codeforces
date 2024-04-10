/**
 *    author:  gary
 *    created: 03.01.2022 22:14:13
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n;
int query(int i){
    cout<<"? "<<i<<endl;ff;
    int x;
    cin>>x;
    return x;
}
int p[10000+20];
void answer(){
    cout<<"! ";
    rb(i,1,n){
        cout<<p[i]<<" ";
    }
    cout<<endl;ff;
}
bool vis[10000+20];
void solve(){
    cin>>n;
    rb(i,1,n) vis[i]=false;
    rb(i,1,n){
        if(!vis[i]){
            int fir=query(i);
            vis[fir]=1;
            int las=fir;
            int tmp;
            while(true){
                tmp=query(i);
                vis[tmp]=1;
                p[las]=tmp;
                las=tmp;
                if(tmp==fir) break;
            }
        }
    }
    answer();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){ 
        solve();
    }
    return 0;
}