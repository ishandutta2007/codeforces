/**
 *    author:  gary
 *    created: 25.10.2021 14:32:34
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
int n,q,k;
inline int read(){
   int x=0;
   char ch=getchar();
   while(ch<'0'||ch>'9'){
       ch=getchar();
   }
   while(ch>='0'&&ch<='9'){
       x=(x<<1)+(x<<3)+(ch^48);
       ch=getchar();
   }
   return x;
}
int a[MAXN];
LL ans[MAXN];
vector<pair<int,pair<int,LL> > > v[MAXN];
set<mp,greater<mp > > s;
void upd(int i,int val){
    if(v[i].size()) s.erase(II(v[i].back().FIR,i));
    pair<int,LL> now;
    now=II(1,val);
    while(!v[i].empty()&&v[i].back().FIR>=val){
        auto Tmp=v[i].back();
        v[i].POB();
        if(v[i].size()) Tmp.SEC.FIR-=v[i].back().SEC.FIR,Tmp.SEC.SEC-=v[i].back().SEC.SEC;
        now.FIR+=Tmp.SEC.FIR;
        now.SEC+=1ll*Tmp.SEC.FIR*val;
    }
    if(v[i].size()) now.SEC+=v[i].back().SEC.SEC,now.FIR+=v[i].back().SEC.FIR;
    // cout<<i<<"____"<<val<<endl;
    s.insert(II(val,i));
    v[i].PB(II(val,now));
}
void modify(int i,int val){
    s.erase(II(v[i].back().FIR,i));
    pair<int,LL> now=v[i].back().SEC;
    v[i].POB();
    if(v[i].size()) now.FIR-=v[i].back().SEC.FIR;
    now.SEC=1ll*now.FIR*val;
    while(!v[i].empty()&&v[i].back().FIR>=val){
        auto Tmp=v[i].back();
        v[i].POB();
        if(v[i].size()) Tmp.SEC.FIR-=v[i].back().SEC.FIR,Tmp.SEC.SEC-=v[i].back().SEC.SEC;
        now.FIR+=Tmp.SEC.FIR;
        now.SEC+=1ll*Tmp.SEC.FIR*val;
    }
    if(v[i].size()) now.SEC+=v[i].back().SEC.SEC,now.FIR+=v[i].back().SEC.FIR;
    // cout<<i<<"____"<<val<<endl;
    s.insert(II(val,i));
    v[i].PB(II(val,now));
}
LL answer(int i,int len){
    LL tot=v[i].back().SEC.SEC;
    len=v[i].back().SEC.FIR-len;
    int l=0,r=v[i].size();
    // cout<<v[i].back().SEC.FIR<<" "<<len<<endl;
    while(l<r-1){
        int mid=(l+r)>>1;
        if(v[i][mid].SEC.FIR<=len){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    // for(auto it:v[i]){
        // cout<<"#"<<it.FIR<<" "<<it.SEC.FIR<<" "<<it.SEC.SEC<<endl;
    // }
    // cout<<v[i][l].SEC.FIR<<' '<<len<<' '<<v[i][l].SEC.SEC<<"_"<<tot<<endl;
    if(v[i][l].SEC.FIR<=len)
    tot-=v[i][l].SEC.SEC,len-=v[i][l].SEC.FIR,l++;
    if(len){
        tot-=1ll*v[i][l].FIR*len;
    }
    return tot;
}
int main(){
    n=read();
    q=read();
    k=read();
    rb(i,1,n) a[i]=read();
    vector<pair<mp,int> > queries;
    rb(T,1,q){
        int l,r;
        scanf("%d%d",&l,&r);
        queries.PB(II(II(l,r),T));
    }
    sort(ALL(queries));
    reverse(ALL(queries));
    int pt=0;
    rl(i,n,1){
        upd(i%k,a[i]);
        while(!s.empty()&&s.begin()->FIR>a[i]){
            // cout<<a[i]<<" "<<s.begin()->FIR<<"__"<<s.begin()->SEC<<endl;
            modify(s.begin()->SEC,a[i]);
        }
        while(pt<q&&queries[pt].FIR.FIR==i) {
            // cout<<queries[pt].FIR.FIR<<" "<<queries[pt].FIR.SEC<<' '<<(queries[pt].FIR.SEC-queries[pt].FIR.FIR+1+k-1)/k<<endl;
            // if(queries[pt].SEC==1)
            ans[queries[pt].SEC]=answer(i%k,(queries[pt].FIR.SEC-queries[pt].FIR.FIR+1+k-1)/k);
            // if(queries[pt].SEC==10){
            //     cout<<queries[pt].FIR.FIR<<" "<<queries[pt].FIR.SEC<<" "<<ans[queries[pt].SEC]<<endl;
            //     exit(0);
            // }
            pt++;
        }
    }
    rb(T,1,q){
        printf("%lld\n",ans[T]);
    }
    return 0;
}