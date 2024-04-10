/**
 *    author:  gary
 *    created: 28.06.2022 22:30:39
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL __int128_t
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
int len(LL A){
    int rest=0;
    while (A){
        rest++;
        A>>=1;
    }
    return rest;
}
LL mod(LL A,LL B){
    // A(x)%B(x)
    while (A>=B){
        int K=len(A)-len(B);
        A^=(B<<K);
    }
    return A;
}
LL mul(LL A,LL B){
    LL ans=0;
    rep(i,35) rep(j,35) ans^=(((A>>i)&1)&((B>>j)&1))<<(i+j);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    reverse(ALL(s));
    LL x=0;
    rep(i,s.length()){
        x<<=1;
        x|=s[i]-'0';
    }
    if(x==0){
        cout<<-1<<endl;
        return 0;
    }
    LL delta=0;
    while (!(x&1)){
        x>>=1;
        delta++;
    }
    if(x==1){
        cout<<(long long)(delta+1)<<' '<<(long long)(delta+2)<<endl;
        return 0;
    }
    // x^k = 1 (mod P)
    // x^{i} mod P ,(0<=i<B)
    // x^{iB} mod P , (0<=i<=B)
    long long B=(1<<((s.length()+1)/2))+20;
    unordered_map<long long,long long> bs;
    LL f=1;// x^i
    long long ans=1e18;
    // cout<<B<<endl;
    // B=37452687+20;
    rep(i,B){
        LL fm=mod(f,x);
        if(bs.find(fm)!=bs.end()){
            check_min(ans,i-bs[fm]);
        }
        bs[fm]=i;
        f=fm<<1;
    }
    // cout<<ans<<endl;
    f=mod(f,x);// x^B mod P
    LL g=f;
    rb(i,1,B){
        if(bs.find(g)!=bs.end()){
            check_min(ans,i*B-bs[g]);
        }
        g=mul(g,f);
        g=mod(g,x);
    }
    if(ans==1e18) cout<<-1<<endl;
    else
    cout<<(long long)(delta+1)<<" "<<(long long)(delta+1+ans)<<endl;
    return 0;
}