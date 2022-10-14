/**
 *    author:  gary
 *    created: 06.02.2022 22:42:25
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
const int MAXN=3e5+2;
int n,q,MOD;
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A-=B;
    if(A<0) A+=MOD;
}
int a[MAXN],b[MAXN],fib[MAXN];
mp addi[MAXN];
bool vis[MAXN];
int cntundo=0;
int zero=0;
void givetag(int i,int x,int y){
    if(i==n+1) return ;
    cntundo-=vis[i];
    add(addi[i].first,y);
    add(addi[i].second,x);
    vis[i]=(addi[i]!=II(0,0));
    cntundo+=vis[i];
}
void doit(int i){
    int C=addi[i].first;
    add(C,addi[i].second);
    zero-=a[i]==0;
    add(a[i],C);
    zero+=a[i]==0;
    givetag(i+1,addi[i].first,C);
    cntundo-=vis[i];
    addi[i]=II(0,0);
    vis[i]=0;
}
void work(int pos){
    if(addi[pos]==II(0,0)) return ;
    doit(pos);
    if(a[pos]==0)
        if(pos!=n)
            work(pos+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q>>MOD;
    fib[1]=fib[2]=1;
    rb(i,3,n) fib[i]=fib[i-1]+fib[i-2],fib[i]%=MOD;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) cin>>b[i];
    rb(i,1,n) addi[i]=II(0,0);
    rb(i,1,n) sub(a[i],b[i]);
    rb(i,1,n) zero+=a[i]==0;
    rb(T,1,q){
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='A'){
            if(l==r){
                zero-=a[l]==0;
                add(a[l],1);
                zero+=a[l]==0;
            }
            else{
                zero-=a[l]==0;
                zero-=a[l+1]==0;
                add(a[l],1);
                add(a[l+1],1);
                zero+=a[l]==0;
                zero+=a[l+1]==0;
                givetag(l+2,1,1);
                int len=r-l+1;
                givetag(r+1,MOD-fib[len-1],MOD-fib[len]);
            }
        }
        else{
            if(l==r){
                zero-=a[l]==0;
                sub(a[l],1);
                zero+=a[l]==0;
            }
            else{
                zero-=a[l]==0;
                zero-=a[l+1]==0;
                sub(a[l],1);
                sub(a[l+1],1);
                zero+=a[l]==0;
                zero+=a[l+1]==0;
                givetag(l+2,MOD-1,MOD-1);
                int len=r-l+1;
                givetag(r+1,fib[len-1],fib[len]);
            }
        }
        for(int i=l;i<=min(n,l+5);i++) work(i);
        work(r+1);
        if(zero==n&&cntundo==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}