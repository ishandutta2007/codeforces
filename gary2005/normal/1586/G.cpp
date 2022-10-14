/**
 *    author:  gary
 *    created: 17.10.2021 20:54:57
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
const int MAXN=4e5+1;
int a[MAXN],b[MAXN];
const int MOD=1e9+7;
int bit[MAXN];
void add(int pos,int val){
    while(pos<MAXN){
        (bit[pos]+=val)%=MOD;
        pos+=pos&-pos;
    }
}
int query(int pos){
    int val=0;
    while(pos){
        val+=bit[pos];
        val%=MOD;
        pos-=pos&-pos;
    }
    return val;
}
map<mp,int> bad;
int mn[MAXN*2];
int main(){
    int n;
    scanf("%d",&n);
    rb(i,1,n){
        scanf("%d%d",&a[i],&b[i]);
    }
    int mx=0;
    int t;
    scanf("%d",&t);
    int y=0;
    memset(mn,-63,sizeof(mn));
    rb(Z,1,t){
        int i;
        scanf("%d",&i);
        mn[b[i]]=a[i];
        bad[II(a[i],b[i])]=1;
        check_max(mx,b[i]);
        if(b[i]==mx) y=a[i];
    }
    rl(i,n+n,1) check_max(mn[i],mn[i+1]);
    vector<mp> r;
    rb(i,1,n){
        if(b[i]<=mx){
            r.PB(II(a[i],b[i]));
        }
    }
    // cerr<<r.size()<<" "<<y<<endl;
    sort(ALL(r));
    int ans=0;
    int cnt=0;
    int tot=0;
    for(auto it:r){
        int val=1;
        val+=tot;
        val%=MOD;
        val-=query(it.SEC);
        val+=MOD;
        val%=MOD;
        if(mn[it.SEC]<it.FIR&&!bad[it]) (val+=MOD-1)%=MOD;
        (tot+=val)%=MOD;
        // ans+=cnt-query(it.SEC);
        // ans++;
        (ans+=val)%=MOD;
        ans%=MOD;
        add(it.SEC,val);
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}