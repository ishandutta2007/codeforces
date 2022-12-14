#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

int n,m;
struct node{
    int l,r,sum;
}T[maxn*40];
int val[maxn],tot;
void update(int &x,int y,int pos,int val,int L,int R){
    x=++tot;T[x]=T[y];
    T[x].sum+=val;
    if (L==R) return;
    int mid=(L+R)/2;
    if (pos<=mid) update(T[x].l,T[y].l,pos,val,L,mid);
    if (mid<pos) update(T[x].r,T[y].r,pos,val,mid+1,R);
}
int query(int x,int l,int r,int L,int R){
    if (!x||(l<=L&&R<=r)) return T[x].sum;
    int mid=(L+R)/2,ret=0;
    if (l<=mid) ret+=query(T[x].l,l,r,L,mid);
    if (mid<r) ret+=query(T[x].r,l,r,mid+1,R);
    return ret;
}
int rootVAL[maxn],rootID[maxn];
map<string,int> MP;
void solve(int i){
    string a,b;int c;
    cin>>a;
    rootID[i]=rootID[i-1];
    rootVAL[i]=rootVAL[i-1];
    fflush(stdout);
    if (a=="set"){
        cin>>b;
        if (MP[b]==0) MP[b]=i;int ID=MP[b];
        int pre=query(rootID[i],ID,ID,1,INF);
        if (pre) update(rootVAL[i],rootVAL[i],pre,-1,1,INF);
        cin>>c;
        update(rootID[i],rootID[i],ID,c-pre,1,INF);
        update(rootVAL[i],rootVAL[i],c,1,1,INF);
    }else if (a=="remove"){
        cin>>b;
        if (MP[b]==0) MP[b]=i;int ID=MP[b];
        int pre=query(rootID[i],ID,ID,1,INF);
        if (pre) update(rootVAL[i],rootVAL[i],pre,-1,1,INF);
        update(rootID[i],rootID[i],ID,-pre,1,INF);
    }else if (a=="query"){
        cin>>b;
        int ID=MP[b];
        if (ID==0) puts("-1");
        else{
            int pre=query(rootID[i],ID,ID,1,INF);
            if (pre==0) puts("-1");
            else cout<<query(rootVAL[i],1,pre-1,1,INF)<<"\n";
        }
    }else if (a=="undo"){
        cin>>c;
        rootID[i]=rootID[i-c-1];
        rootVAL[i]=rootVAL[i-c-1];
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    FOR(i,1,n) solve(i);
}
/*
*/