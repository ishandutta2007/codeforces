/**
 *    author:  gary
 *    created: 31.12.2021 21:05:47
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
const int MAXN=150000+20;
int n,a[MAXN];
int son[MAXN*30][2],siz[MAXN*30];
int cnt=1;
void insert(int now,int val,int pos=29){
    siz[now]++;
    if(pos==-1) return ;
    int bt=(val>>pos)&1;
    if(!son[now][bt]){
        son[now][bt]=++cnt;
    }
    insert(son[now][bt],val,pos-1);
}
int X;
const int MOD=998244353;
int pw2[MAXN];
int solve2(int x,int y,int pos){
    if(pos==-1){
        return pw2[siz[x]+siz[y]];
    }
    if(x+y==0) return 1;
    if((X>>pos)&1){
        return 1ll*solve2(son[x][0],son[y][1],pos-1)*solve2(son[x][1],son[y][0],pos-1)%MOD;
    }
    else{
        int answer=0;
        (answer+=pw2[siz[x]])%=MOD;
        (answer+=pw2[siz[y]])%=MOD;
        (answer+=MOD-1)%=MOD;
        answer+=solve2(son[x][0],son[y][0],pos-1);
        answer%=MOD;
        (answer+=solve2(son[x][1],son[y][1],pos-1))%=MOD;
        (answer+=MOD-pw2[siz[son[x][0]]])%=MOD;
        (answer+=MOD-pw2[siz[son[x][1]]])%=MOD;
        (answer+=MOD-pw2[siz[son[y][0]]])%=MOD;
        (answer+=MOD-pw2[siz[son[y][1]]])%=MOD;
        (answer+=2)%=MOD;
        return answer;
    }
}
int solve(int now,int pos){
    if(pos==-1) return pw2[siz[now]];
    if(now==0) return 1;
    int ans=0;
    if((X>>pos)&1){
        (ans+=solve2(son[now][0],son[now][1],pos-1))%=MOD;
    }
    else{
        (ans+=solve(son[now][0],pos-1))%=MOD;
        (ans+=solve(son[now][1],pos-1))%=MOD;
        (ans+=MOD-1)%=MOD;
    }
    // cout<<pos<<" "<<ans<<endl;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>X;
    pw2[0]=1;
    rb(i,1,n) pw2[i]=(pw2[i-1]<<1)%MOD;
    rb(i,1,n) cin>>a[i],insert(1,a[i]);
    cout<<solve(1,29)-1<<endl;
    return 0;
}