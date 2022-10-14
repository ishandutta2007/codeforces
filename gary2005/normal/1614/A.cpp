/**
 *    author:  gary
 *    created: 26.11.2021 19:02:02
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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,l,r,k;
        cin>>n>>l>>r>>k;
        vector<int> a;
        rep(i,n) {
            int ai;
            cin>>ai;
            if(ai<=r&&ai>=l)
            a.PB(ai);
        }
        sort(ALL(a));
        int cnt=0;
        for(auto it:a){
            cnt+=k>=it;
            if(k>=it)
            k-=it;
        }
        cout<<cnt<<endl;
    }
    return 0;
}