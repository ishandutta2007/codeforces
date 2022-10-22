/**
 *    author:  gary
 *    created: 06.10.2021 15:05:54
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
const int MAXN=2e5+1;
int cnt[MAXN],s[100],c[100],tot=0;
int n,m,k;
vector<int> A,B,C,preA,preB,preC;
void addi(int x){
    tot++;
    cnt[x]++;
    c[(x-1)/100]++;
    s[(x-1)/100]+=x;
}
int query(int x){
    int l=1,r=100;
    int rest=0;
    rep(i,100){
        if(c[i]<x){
            x-=c[i];
            rest+=s[i];
        }
        else{
            rb(i,l,r){
                int t=min(x,cnt[i]);
                rest+=t*i;
                x-=t;
            }
            return rest;
        }
        l+=100;
        r+=100;
    }
    return rest;
}
bool cmp(mp A,mp B){
    return A.SEC<B.SEC;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    int ans=-1;
    vector<mp> AA,BB,CC,DD;
    rb(i,1,n){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(a&&b){
            A.PB(t);
            AA.PB(II(i,t));
        }
        else if(a){
            B.PB(t);
            BB.PB(II(i,t));
        }
        else if(b){
            C.PB(t);
            CC.PB(II(i,t));
        }
        else addi(t),DD.PB(II(i,t));
    }
    preA.PB(0);
    sort(ALL(A));
    for(auto it:A) preA.PB(preA.back()+it);
    sort(ALL(B));
    preB.PB(0);
    for(auto it:B) preB.PB(preB.back()+it);
    sort(ALL(C));
    preC.PB(0);
    for(auto it:C) preC.PB(preC.back()+it);
    int y;
    rep(i,A.size()+1){
        if(i>m) break;
        int extr=max(0,k-i);
        while(C.size()>extr) addi(C.back()),C.POB();
        while(B.size()>extr) addi(B.back()),B.POB();
        if(extr<=min(B.size(),C.size())){
            if(extr*2+i<=m&&m-extr*2-i<=tot){
                if(ans==-1||ans>query(m-extr*2-i)+preC[extr]+preB[extr]+preA[i]){
                    ans=query(m-extr*2-i)+preC[extr]+preB[extr]+preA[i];
                    y=i;
                }
            }
        }
    }
    if(ans==-1)
    cout<<ans<<endl;
    else{
        cout<<ans<<endl;
        sort(ALL(AA),cmp);
        sort(ALL(BB),cmp);
        sort(ALL(CC),cmp);
        rep(i,y) printf("%d ",AA[i].FIR);
        int ex=max(0,k-y);
        rep(i,ex) printf("%d %d ",BB[i].FIR,CC[i].FIR);
        rep(i,BB.size()) if(i>=ex) DD.PB(BB[i]);
        rep(i,CC.size()) if(i>=ex) DD.PB(CC[i]);
        sort(ALL(DD),cmp);
        ex=m-2*ex-y;
        rep(i,ex) printf("%d ",DD[i].FIR);
        puts("");
    }
    return 0;
}