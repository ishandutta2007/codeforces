/**
 *    author:  gary
 *    created: 17.03.2022 13:58:01
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
const int MAXN=120000+10;
int n,p[MAXN],B;
vector<mp> queries[MAXN];// [l,id]
long long ans[MAXN];
long long a[MAXN];
long long h[MAXN];
struct BLOCK{
    int l,r;
    int tag,mn,cnt,t,mnadd;
    long long his;
    void pushdown(){
        rb(i,l,r){
            if(mnadd+a[i]==0) h[i]+=t;
            a[i]+=tag;
        }
        mnadd=0;
        t=0;
        tag=0;
    }
    void rebuild(){
        mnadd=0;
        t=0;
        cnt=0;
        mn=INF;
        his=0;
        rb(i,l,r){
            his+=h[i];
            if(mn>a[i]){
                mn=a[i];
                cnt=0;
            }
            if(mn==a[i]) cnt++;
        }
    }
    void flush(){
        if(mn==0) his+=cnt;
        if(tag==mnadd) t++;
    }
};
vector<BLOCK> v;
void add(int l,int r,int x){
    for(auto &it:v){
        if(it.l>=l&&it.r<=r){
            it.tag+=x;
            it.mn+=x;
            if(it.tag<it.mnadd) it.t=0,it.mnadd=it.tag;
            continue;
        }
        int L,R;
        L=max(l,it.l);
        R=min(r,it.r);
        if(L<=R){
            it.pushdown();
            rb(i,L,R) a[i]+=x;
            it.rebuild();
        }
    }
}
long long query(int l,int r){
    long long rest=0;
    for(auto &it:v){
        if(it.l>=l&&it.r<=r){
            rest+=it.his;
            continue;
        }
        int L,R;
        L=max(l,it.l);
        R=min(r,it.r);
        if(L<=R){
            it.pushdown();
            rb(i,L,R) rest+=h[i];
        }
    }
    return rest;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    B=ceil(sqrt(n));
    rb(i,1,n) cin>>p[i];
    int q;
    cin>>q;
    rb(i,1,q){
        int l,r;
        cin>>l>>r;
        queries[r].PB(II(l,i));
    }
    rb(i,1,n) a[i]=1;
    for(int l=1;l<=n;l+=B){
        BLOCK tmp;
        tmp.l=l;
        tmp.r=min(n,l+B-1);
        tmp.tag=0;
        tmp.his=0;
        tmp.rebuild();
        v.PB(tmp);
    }
    stack<mp> mx,mn;
    rb(i,1,n){
        int to=i;
        while (!mx.empty()&&mx.top().second<p[i]){
            add(mx.top().first,to-1,p[i]-mx.top().second);
            to=mx.top().first;
            mx.pop();
        }
        mx.push(II(to,p[i]));
        to=i;
        while (!mn.empty()&&mn.top().second>p[i]){
            add(mn.top().first,to-1,mn.top().second-p[i]);
            to=mn.top().first;
            mn.pop();
        }
        mn.push(II(to,p[i]));
        add(1,i,-1);
        for(auto &it:v) it.flush();
        for(auto it:queries[i]){
            ans[it.second]=query(it.first,i);
        }
    }
    rb(i,1,q) cout<<ans[i]<<endl;
    return 0;
}