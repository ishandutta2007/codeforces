/**
 *    author:  gary
 *    created: 08.09.2021 22:33:03
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
const int MAXN=3e5+1;
map<int,int> h,v;
bool cmp(mp A,mp B){
    return A.SEC<B.SEC;
}
void solve(){
    h.clear();
    v.clear();
    int n,m;
    scanf("%d%d",&n,&m);
    int k;
    scanf("%d",&k);
    vector<mp> H,V;
    rb(i,1,n){
        int xi;
        scanf("%d",&xi);
        v[xi]=1;
    }
    rb(i,1,m){
        int yi;
        scanf("%d",&yi);
        h[yi]=1;
    }
    rb(i,1,k){
        int x,y;
        scanf("%d%d",&x,&y);
        if(h.find(y)!=h.end()&&v.find(x)!=v.end()){
            continue;
        }
        if(h.find(y)!=h.end()){
            H.PB(II(x,y));
        }
        else{
            V.PB(II(x,y));
        }
    }
    sort(ALL(V),cmp);
    int pt=0;
    LL rest=0;
    for(auto ite=h.begin();next(ite)!=h.end();ite++){
        int U=next(ite)->FIR;
        int cnt=0;
        vector<int> Tmp;
        while(pt<V.size()&&V[pt].SEC<U){
            Tmp.PB(V[pt].FIR);
            ++pt;
        }
        sort(ALL(Tmp));
        int pre=-1;
        int c=0;
        // cerr<<Tmp.size()<<"_"<<U<<endl;
        for(auto it:Tmp){
            if(it!=pre){
                pre=it;
                c+=cnt;
                cnt=0;
            }
            cnt++;
            rest+=c;
        }
    }
    sort(ALL(H));
    pt=0;
    for(auto ite=v.begin();next(ite)!=v.end();ite++){
        int U=next(ite)->FIR;
        int cnt=0;
        vector<int> Tmp;
        while(pt<H.size()&&H[pt].FIR<U){
            Tmp.PB(H[pt].SEC);
            pt++;
        }
        sort(ALL(Tmp));
        int pre=-1;
        int c=0;
        for(auto it:Tmp){
            if(it!=pre){
                pre=it;
                c+=cnt;
                cnt=0;
            }
            cnt++;
            rest+=c;
        }
    }
    printf("%lld\n",rest);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}