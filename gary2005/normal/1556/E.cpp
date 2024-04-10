/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+1;
int n,q;
int a[MAXN],b[MAXN],c[MAXN];
LL z[MAXN];
int tmp[MAXN];
int cnt[MAXN];
LL answer[MAXN];
LL mx[MAXN][17];
LL mn[MAXN][17];
int lg[MAXN];
LL query(int l,int r){
    int len=r-l+1;
    len=lg[len];
    return max(mx[l][len],mx[r-(1<<len)+1][len]);
}
LL querymin(int l,int r){
    int len=r-l+1;
    len=lg[len];
    return min(mn[l][len],mn[r-(1<<len)+1][len]);
}
const int BLOCK=333;
bool cmp (pair<mp,int> A,pair<mp,int> B){
    if(A.FIR.FIR/BLOCK!=B.FIR.FIR/BLOCK) return A.FIR.FIR<B.FIR.FIR;
    return A.FIR.SEC<B.FIR.SEC;
}
int main(){
    scanf("%d%d",&n,&q);
    lg[1]=0;
    rb(i,2,n) lg[i]=lg[i>>1]+1;
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,1,n) scanf("%d",&b[i]);
    rb(i,1,n) c[i]=a[i]-b[i];
    rb(i,1,n) z[i]=z[i-1]+c[i];
    rb(i,1,n) mx[i][0]=mn[i][0]=z[i];
    rb(j,1,16) rb(i,1,n) if((i+(1<<j)-1)<=n){
        mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);   
    }
    vector<LL> fuck;
    rb(i,1,n) fuck.PB(z[i]);
    sort(ALL(fuck));
    fuck.erase(unique(ALL(fuck)),fuck.end());
    rb(i,1,n) tmp[i]=lower_bound(ALL(fuck),z[i])-fuck.begin();
    rb(i,1,q){
        int l,r;
        scanf("%d%d",&l,&r);
        if(z[r]-z[l-1]!=0){
            answer[i]=-1;
            continue;
        }
        if(query(l,r)-z[l-1]>0){
            answer[i]=-1;
            continue;
        }
        answer[i]=-(querymin(l,r)-z[l-1]);
    }
    rb(i,1,q){
        printf("%lld\n",answer[i]);
    }
    return 0;
}