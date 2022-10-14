/**
 *    author:  gary
 *    created: 17.10.2021 19:02:41
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
const int MAXN=1e5+1;
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    map<int,int> M;
    rb(i,1,m){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        M[b]=1;
    }
    rb(i,1,n){
        if(M.find(i)==M.end()){
            rb(j,1,n){
                if(i!=j) printf("%d %d\n",i,j);
            }
            return ;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}