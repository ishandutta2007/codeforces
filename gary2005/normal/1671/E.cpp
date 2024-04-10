/**
 *    author:  gary
 *    created: 23.04.2022 00:07:43
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
string s[1<<18];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    n=1<<n;
    rb(i,1,n-1){
        char c;
        cin>>c;
        s[i].PB(c);
    }
    int cnt=0;
    rl(i,(n>>1)-1,1){
        if(s[i<<1]<s[i<<1|1])
        s[i]=s[i<<1]+s[i]+s[i<<1|1];
        else
        s[i]=s[i<<1|1]+s[i]+s[i<<1];
        cnt+=s[i<<1]!=s[i<<1|1];
    }
    int ans=1;
    rb(i,1,cnt) ans=(ans+ans)%998244353;
    cout<<ans<<endl;
    return 0;
}