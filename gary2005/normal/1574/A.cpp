/**
 *    author:  gary
 *    created: 20.09.2021 22:34:38
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
void solve(){
    int n;
    cin>>n;
    rb(i,1,n){
        rb(j,1,2*n){
            if(j<=2*i){
                if(j<=i) cout<<"(";
                else cout<<")";
            }
            else{
                if(j%2==1){
                    cout<<"(";
                }
                else{
                    cout<<")";
                }
            }
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}