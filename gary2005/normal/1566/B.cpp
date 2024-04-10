/**
 *    author:  gary
 *    created: 12.09.2021 22:32:54
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
        string s;
        cin>>s;
        int n=s.length();
        int cnt0,cnt1;
        cnt0=cnt1=0;
        rep(i,n){
            if(s[i]=='1') cnt1++;
            else cnt0++;
        }
        int ans=2;
        if(cnt1==0){
            ans=1;
        }
        if(cnt0==0){
            ans=0;
        }
        int l,r;
        l=-1;
        r=INF;
        rep(i,n){
            if(s[i]=='0'){
                if(l==-1) l=i;
                r=i;
            }
        }
        if(ans&&cnt0==r-l+1) ans=1;
        cout<<ans<<endl;
    }
    return 0;
}