/**
 *    author:  gary
 *    created: 06.03.2022 17:47:57
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
const int MAXN=200000+20;
int a[200000+20],b[200000+20];
int cnt[200000+20];
const int MOD=998244353;
int fact[MAXN+1],ifact[MAXN+1];
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
void genmath(){
    fact[0]=1;
    rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
    ifact[MAXN]=inv(fact[MAXN]);
    rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
}
int comb(int A,int B){
    if(A<0||B<0) return 0;
    if(A<B) return 0;
    return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A+=MOD-B;
    if(A>=MOD) A-=MOD;
}
struct BIT{
    int tree[MAXN];
    void clear(){memset(tree,0,sizeof(tree));}
    void addi(int pos,int val){
        while(pos<MAXN){add(tree[pos],val);pos+=pos&-pos;}
    }
    int query(int pos){
        int s=0;
        while(pos){
            add(s,tree[pos]);
            pos-=pos&-pos;
        }
        return s;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
    BIT(){clear();}
}bs;
void modify(int pos,int val){
    bs.addi(pos,(MOD-(bs.query(pos)-bs.query(pos-1)+MOD)%MOD)%MOD);
    bs.addi(pos,val);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    genmath();
    int n,m;
    cin>>n>>m;
    rb(i,1,n) cin>>a[i],cnt[a[i]]++;
    rb(i,1,m) cin>>b[i];
    int ans=0;
    if(n<m){
        rb(i,1,n){
            cnt[b[i]]--;
        }
        if(*max_element(cnt+1,cnt+1+200000)==0){
            ans++;
        }
        memset(cnt,0,sizeof(cnt));
        rb(i,1,n) cnt[a[i]]++;
    }
    int prod=1;
    rb(i,1,200000){
        prod=1ll*prod*ifact[cnt[i]]%MOD;
    }
    rb(i,1,200000){
        if(cnt[i])
            modify(i,1ll*ifact[cnt[i]-1]*fact[cnt[i]]%MOD);
        else
            modify(i,0);
    }
    rb(i,1,min(n,m)){
        add(ans,1ll*bs.query(b[i]-1)*prod%MOD*fact[n-i]%MOD);
        cnt[b[i]]--;
        if(cnt[b[i]]<0) break;
        if(cnt[b[i]])
        modify(b[i],1ll*ifact[cnt[b[i]]-1]*fact[cnt[b[i]]]%MOD);
        else
        modify(b[i],0);
        prod=1ll*prod*fact[cnt[b[i]]+1]%MOD;
        prod=1ll*prod*ifact[cnt[b[i]]]%MOD;
    }
    cout<<ans<<endl;
    return 0;
}