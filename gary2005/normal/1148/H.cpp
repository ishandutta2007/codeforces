/**
 *    author:  gary
 *    created: 06.10.2021 13:09:35
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
const int MAXN=2e5+20;
const int N=1<<18;
struct rect
{
    int l,r,u,d;
    rect(){l=r=u=d=0;}
    rect(int L,int R,int D,int U){
        l=L,r=R,u=U,d=D;
    }
    LL area(){
        return 1ll*(u-d+1)*(r-l+1);
    }
    LL intersect(rect ano){
        int L,R,U,D;
        L=max(l,ano.l);
        R=min(r,ano.r);
        U=min(u,ano.u);
        D=max(d,ano.d);
        if(L<=R&&U>=D){
            return 1ll*(R-L+1)*(U-D+1);
        }
        else return 0;
    }
};
int n;
struct mextree
{
    int cnt,tree[N+N];
    mextree(){memset(tree,0,sizeof(tree));cnt=0;}
    void set(int pos,int val){
        pos+=N-1;
        tree[pos]=val;
        pos>>=1;
        while(pos){
            tree[pos]=min(tree[pos<<1],tree[pos<<1|1]);
            pos>>=1;
        }
    }
    void add(int val){// add val to the back
        ++cnt;
        set(val+1,cnt);
    }
    int querymin(int a,int b,int L,int now=1,int l=1,int r=N+1){
        // [a,b]<L
        if(l==r-1) return l;
        int mid=(l+r)>>1;
        if(tree[now<<1]<L) return querymin(a,b,L,now<<1,l,mid);
        return querymin(a,b,L,now<<1|1,mid,r);
    }
    int querymex(int L){//a[L]...a[cnt]mex
        return querymin(1,N+1,L)-1;
    }
}mex;
vector<pair<LL,rect > > rec[MAXN];
vector<LL> len[MAXN];
mp bk[MAXN];
int sins[MAXN];
vector<mp> div(mp rang){
    int L,R;
    L=rang.FIR;R=rang.SEC;
    vector<mp> rest;
    while(mex.querymex(L)!=mex.querymex(R)){
        int l=L,r=R;
        int Tmp=mex.querymex(L);
        while(l<r-1){
            int mid=(l+r)>>1;
            if(Tmp==mex.querymex(mid)) l=mid;
            else r=mid;
        }
        rest.PB(II(L,l));
        L=l+1;
    }
    rest.PB(II(L,R));
    return rest;
}
void addrect(int col,rect R){
    if(rec[col].empty()) rec[col].PB(II(R.area(),R)),len[col].PB(R.r-R.l+1);
    else rec[col].PB(II(rec[col].back().FIR+R.area(),R)),len[col].PB(len[col].back()+R.r-R.l+1);
}
int I;
void Gao(int a){
    mex.add(a);
    if(sins[a]==INF) return;
    if(sins[a]!=I){
        addrect(a,rect(sins[a],I-1,bk[a].FIR,bk[a].SEC));
    }
    sins[a]=INF;
    auto V = div(bk[a]);
    for(auto it:V){
        int mx=mex.querymex(it.FIR);
        // cout<<it.FIR<<' '<<it.SEC<<" "<<mx<<endl;
        if(sins[mx]!=INF){
            addrect(mx,rect(sins[mx],I-1,bk[mx].FIR,bk[mx].SEC));
            if(bk[mx].SEC+1==it.FIR) bk[mx].SEC=it.SEC;
            sins[mx]=I;
        }
        else
            sins[mx]=I,bk[mx]=it;        
    }
}
LL Query(int l,int r,int k){
    if(sins[k]!=INF) addrect(k,rect(sins[k],I,bk[k].FIR,bk[k].SEC));
    // int tmpans=0;
    // for(auto it:rec[k])
    // {
    //     if(it.SEC.intersect(rect(l,r,l,r))){
    //         cout<<"OOOOOOOOOOO"<<it.SEC.l<<" "<<it.SEC.r<<" "<<it.SEC.d<<' '<<it.SEC.u<<endl;
    //     }
    //     tmpans+=it.SEC.intersect(rect(l,r,l,r));
    // }
    // if(sins[k]!=INF) rec[k].POB();
    // return tmpans;
    if(rec[k].empty()) return 0;
    int lb1=0,rb1=rec[k].size()-1;
    while(lb1<rb1){
        int mid=(lb1+rb1)>>1;
        auto tmp=rec[k][mid].SEC;
        if(!tmp.intersect(rect(l,r,l,r))&&(tmp.r<l||tmp.u<l)){
            lb1=mid+1;
        }
        else{
            rb1=mid;
        }
    }
    if(!rec[k][lb1].SEC.intersect(rect(l,r,l,r))){
    if(sins[k]!=INF) rec[k].POB(),len[k].POB(); 
    return 0;}
    int lb2=lb1,rb2=rec[k].size();
    while(lb2<rb2-1){
        int mid=(lb2+rb2)>>1;
        auto tmp=rec[k][mid].SEC;
        if(!tmp.intersect(rect(l,r,l,r))) rb2=mid;
        else lb2=mid;
    }
    // cout<<lb1<<' '<<rec[k][lb1+1].SEC.l<<' '<<rec[k][lb1+1].SEC.r<<' '<<rec[k][lb1+1].SEC.d<<' '<<rec[k][lb1+1].SEC.u<<" "<<rec[k][lb2].SEC.area()<<endl;
    LL ans=0;
    ans+=rec[k][lb2].FIR;
    if(lb1)
    ans-=rec[k][lb1-1].FIR;
    // cout<<ans<<endl;
    if(rec[k][lb1].SEC.l<l) ans-=1ll*(l-rec[k][lb1].SEC.l)*(min(r,rec[k][lb1].SEC.u)-max(l,rec[k][lb1].SEC.d)+1);
    if(rec[k][lb2].SEC.r>r) ans-=1ll*(rec[k][lb2].SEC.r-r)*(min(r,rec[k][lb2].SEC.u)-max(l,rec[k][lb2].SEC.d)+1);
    // cout<<ans<<endl;
    if(rec[k][lb1].SEC.d<l){
        lb2=lb1,rb2=rec[k].size();
        while(lb2<rb2-1){
            int mid=(lb2+rb2)>>1;
            auto tmp=rec[k][mid].SEC;
            if(tmp.d<l&&tmp.intersect(rect(l,r,l,r))) lb2=mid;
            else rb2=mid;
        }
        // cout<<lb1<<' '<<lb2<<" "<<rec[k][lb2].SEC.d<<" "<<rec[k].size()<<" "<<len[k][lb2]-len[k][lb1-1]<<endl;
        ans-=1ll*(l-rec[k][lb1].SEC.d)*(len[k][lb2]);
        if(lb1)
        ans+=1ll*(l-rec[k][lb1].SEC.d)*(len[k][lb1-1]);
    }
    if(sins[k]!=INF) rec[k].POB(),len[k].POB();
    return ans;
}
int main(){
    memset(sins,63,sizeof(sins));
    scanf("%d",&n);
    LL lans=0;
    rb(i,1,n){
        I=i;
        int a,l,r,k;
        scanf("%d%d%d%d",&a,&l,&r,&k);
        a=(lans+a)%(n+1);
        l=(lans+l)%i+1;
        r=(lans+r)%i+1;
        if(l>r) swap(l,r);
        k=(lans+k)%(n+1);
        // cout<<"-------------"<<a<<' '<<l<<' '<<r<<' '<<k<<endl;
        if(sins[0]==INF){
            sins[0]=i;
            bk[0]=II(i,i);
            // cout<<bk[0].FIR<<" "<<bk[0].SEC<<" "<<i<<endl;
        }
        else{
            addrect(0,rect(sins[0],i-1,bk[0].FIR,bk[0].SEC));
            sins[0]=i;
            bk[0].SEC=i;
        }
        Gao(a);// push back a
        lans=Query(l,r,k);
        // if(lans==45) lans=43;
        printf("%lld\n",lans);
    }
    return 0;
}