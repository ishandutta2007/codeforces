/**
 *    author:  gary
 *    created: 21.12.2021 22:20:07
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
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int w=60;
const int MAXN=2002;
const int B=(MAXN+w-1)/w;
struct bs{
    LL val[B];
    int cnt;
    unsigned LL hv;
    bs(){
        cnt=0;
        hv=0;
        memset(val,0,sizeof(val));
    }
    void flip(int l,int r){
        for(int i=0;i<=r;i+=w){
            int l_,r_;
            l_=max(l,i);
            r_=min(r,i+w-1);
            if(l_<=r_){
                l_-=i;
                r_-=i-1;
                val[i/w]^=(1ll<<r_)-1;
                val[i/w]^=(1ll<<l_)-1;
            }
        }
        cnt=0;
        hv=0;
        rep(i,B){
            cnt+=__builtin_popcountll(val[i]);
            hv^=hv<<5;
            hv^=val[i];
        }
    }
    bool in(const bs & ano){
        rep(i,B) if((val[i]&ano.val[i])^val[i]) return false;
        return true;
    }
};
int n,m,q;
bs s[MAXN];
int main(){
    // freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    set<int> cnt;
    multiset<pair<pair<int,unsigned LL>,int> > se;
    rb(i,1,n) se.insert(II(II(s[i].cnt,s[i].hv),i));
    rb(T,1,q){
        int a,l,r;
        cin>>a>>l>>r;
        auto old=se.find(II(II(s[a].cnt,s[a].hv),a));
        if(old!=se.begin()){
            if(!(s[prev(old)->SEC].in(s[a])))
            cnt.erase(a);
        }
        if(next(old)!=se.end()){
            if(!(s[a].in(s[next(old)->SEC])))
            cnt.erase(next(old)->SEC);
        }
        old=se.erase(old);
        if(old!=se.begin()&&old!=se.end()){
            if(!(s[prev(old)->SEC].in(s[old->SEC])))
            cnt.insert(old->SEC);
        }
        s[a].flip(l-1,r-1);
        se.insert(II(II(s[a].cnt,s[a].hv),a));
        old=se.find(II(II(s[a].cnt,s[a].hv),a));
        if(old!=se.begin()&&next(old)!=se.end()){
            if(!(s[prev(old)->SEC].in(s[next(old)->SEC])))
            cnt.erase(next(old)->SEC);
        }
        if(old!=se.begin()){
            if(!(s[prev(old)->SEC].in(s[a])))
            cnt.insert(a);
        }
        if(next(old)!=se.end()){
            if(!(s[a].in(s[next(old)->SEC])))
            cnt.insert(next(old)->SEC);
        }
        if(cnt.empty()){
            cout<<-1<<endl;
        }
        else{
            a=*cnt.begin();
            old=se.find(II(II(s[a].cnt,s[a].hv),a));
            int b=prev(old)->SEC;
            LL x,y;
            x=y=-1;
            rep(i,B){
                if((s[b].val[i]&s[a].val[i])!=s[b].val[i]){
                    if(x==-1){
                        x=(s[b].val[i])^((s[b].val[i]&s[a].val[i]));
                        x=x&-x;
                        LL now=x;
                        x=0;
                        while(now!=1){
                            now>>=1;
                            x++;
                        }
                        x+=i*w;
                    }
                }
                if((s[b].val[i]&s[a].val[i])!=s[a].val[i]){
                    if(y==-1){
                        y=(s[a].val[i])^((s[b].val[i]&s[a].val[i]));
                        y=y&-y;
                        LL now=y;
                        y=0;
                        while(now!=1){
                            now>>=1;
                            y++;
                        }
                        y+=i*w;
                    }
                }
            }
            x++;
            y++;
            cout<<min(a,b)<<" "<<min(x,y)<<" "<<max(a,b)<<" "<<max(x,y)<<endl;
        }
    }
    return 0;
}