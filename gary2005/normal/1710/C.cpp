/**
 *    author:  gary
 *    created: 28.07.2022 10:50:04
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
const int MAXN=2e5+200;
int dp[MAXN][512];
int trans[512][2][8];
const int MOD=998244353;
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    if(s=="1"){cout<<0<<endl;return 0;}
    vector<int> v;
    rep(i,s.length()) v.push_back(s[i]-'0');
    vector<int> nw;
    while (!v.empty()&&v.back()==1){
        v.pop_back();
        nw.push_back(0);
    }
    if(v.size()) nw.push_back(1),v.pop_back();
    else nw.push_back(1);
    while (!v.empty()){
        nw.push_back(v.back());
        v.pop_back();
    }
    v.swap(nw);
    rep(j,8) rep(k,8) rep(l,8) rep(f,2) rep(mask,8){
        int newj,newk,newl;
        newj=0;
        newk=0;
        newl=0;
        int A,B,C;
        A=(mask>>2)&1;
        B=(mask>>1)&1;
        C=mask&1;
        int a,b,c;
        a=A^B,b=B^C,c=A^C;
        if((a+b+((k>>2)&1))%2>c) newj|=1<<2;
        if(a+b+((k>>2)&1)>1) newk|=1<<2;
        if((a+b+((k>>2)&1))%2==c) newj|=(j>>2)<<2;
        if((c+b+((k>>1)&1))%2>a) newj|=1<<1;
        if(c+b+((k>>1)&1)>1) newk|=1<<1;
        if((c+b+((k>>1)&1))%2==a) newj|=((j>>1)&1)<<1;
        if((c+a+((k)&1))%2>b) newj|=1;
        if(c+a+((k)&1)>1) newk|=1;
        if((c+a+((k)&1))%2==b) newj|=j&1;
        if(A==f) newl|=(l>>2)<<2;
        if(A<f) newl|=1<<2;
        if(B==f) newl|=((l>>1)&1)<<1;
        if(B<f) newl|=1<<1;
        if(C==f) newl|=l&1;
        if(C<f) newl|=1;
        // if(j==0&&k==0&&l==0&&f==1&&mask==0) cout<<newj<<" "<<newk<<" "<<newl<<endl;
        trans[(j<<6)|(k<<3)|l][f][mask]=(newj<<6)|(newk<<3)|newl;
    }
    // cout<<trans[12][1][2]<<endl;
    dp[0][0]=1;
    rb(i,1,10) v.push_back(0);
    rep(i,v.size()) rep(j,512) if(dp[i][j]) {
        int &val=dp[i][j];
        rep(mask,8){
            add(dp[i+1][trans[j][v[i]][mask]],val);
        }
    }
    cout<<dp[v.size()][455]<<endl;
    return 0;
}