/**
 *    author:  gary
 *    created: 23.02.2022 18:08:46
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
const int N=1<<18;
int L[N],R[N],C[N];
int tag[N+N];
int delta[N+N];
vector<int> conta[N+N];
int cnt[N+N];
bool ok[N];
set<int> one;
void upd(int pos){
    // cout<<"----"<<pos<<endl;
    pos+=N-1;
    int siz=1;
    while(pos){
        cnt[pos]++;
        delta[pos]++;
        // cout<<pos<<"$"<<cnt[pos]<<" "<<conta[pos].size()<<" "<<siz<<endl;
        if(cnt[pos]>=siz-1){
        for(auto it:conta[pos]){
            C[it]+=delta[pos];
            if(C[it]==R[it]-L[it]){
                ok[*one.lower_bound(L[it])]=1;
            }
        }
        delta[pos]=0;
        }
        pos>>=1;
        siz<<=1;
    }
}
int query(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return 0;
    if(r<=b&&l>=a){
        return cnt[now];
    }
    int mid=(l+r)>>1;
    return query(a,b,now<<1,l,mid)+query(a,b,now<<1|1,mid,r);
}
void addi(int a,int b,int val,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a){
        // cout<<now<<","<<a<<' '<<b<<" "<<l<<' '<<r<<"___\n";
        C[val]-=delta[now];
        conta[now].PB(val);
        return ;
    }
    int mid=(l+r)>>1;
    addi(a,b,val,now<<1,l,mid);
    addi(a,b,val,now<<1|1,mid,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    rb(i,1,n) one.insert(i);
    rb(i,1,q){
        int t;
        cin>>t;
        if(t==0){
            int l,r,x;
            cin>>l>>r>>x;
            if(x==0){
                auto ite=one.lower_bound(l);
                vector<int> v;
                while(ite!=one.end()&&*ite<=r){
                    v.PB(*ite);
                    ite=one.erase(ite);
                }
                for(auto it:v) upd(it);
            }
            else{
                L[i]=l;
                R[i]=r;
                C[i]=query(l,r+1);
                if(C[i]==R[i]-L[i]){
                    ok[*one.lower_bound(L[i])]=1;
                }
                else{
                    addi(l,r+1,i);
                }
            }
        }
        else{
            int x;
            cin>>x;
            if(one.find(x)==one.end()){
                cout<<"NO\n";
            }
            else{
                if(ok[x]){
                    cout<<"YES\n";
                }
                else{
                    cout<<"N/A\n";
                }
            }
        }
    }
    return 0;
}//