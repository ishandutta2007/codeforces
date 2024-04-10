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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int l[100000+20],r[100000+20],c[100000+20];
void solve(){
    int n;
    cin>>n;
    rb(i,1,n) cin>>l[i]>>r[i]>>c[i];
    map<mp,int> M;
    map<int,int> Lm;
    map<int,int> Rm;
    int L,R;
    L=INF,R=-INF;
    rb(i,1,n){
        check_min(L,l[i]);
        check_max(R,r[i]);
        if(Lm.find(l[i])==Lm.end()||Lm[l[i]]>c[i]) Lm[l[i]]=c[i];
        if(Rm.find(r[i])==Rm.end()||Rm[r[i]]>c[i]) Rm[r[i]]=c[i];
        if(M.find(II(l[i],r[i]))==M.end()||M[II(l[i],r[i])]>c[i]) M[II(l[i],r[i])]=c[i];
        int answer=2e9;
        if(M.find(II(L,R))!=M.end()) answer=M[II(L,R)];
        check_min(answer,Lm[L]+Rm[R]);
        // cout<<"___";
        cout<<answer<<endl;
    }
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