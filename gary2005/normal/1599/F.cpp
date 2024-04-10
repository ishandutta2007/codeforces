/**
 *    author:  gary
 *    created: 12.10.2021 09:46:41
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
const int MOD=1e9+7;
const int MAXN=2e5+1;
int quick(int A,int B){
    int res=1;
    int tmp=A;
    while(B){
        if(B&1)
            res=1ll*res*tmp%MOD;
        B>>=1;
        tmp=1ll*tmp*tmp%MOD;
    }
    return res;
}
void add(int & A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int n,q;
int a[MAXN];
int comb[11][11];
int pw[MAXN][11];
int pws[MAXN][11];
int main(){
    scanf("%d%d",&n,&q);
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,0,10) comb[i][0]=1;
    rb(i,1,10) rb(j,1,10) comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
    rb(i,0,n-1) rb(j,0,10) pw[i+1][j]=pw[i][j],add(pw[i+1][j],quick(i,j));
    rb(k,1,10) rb(i,1,n) pws[i][k]=pws[i-1][k],add(pws[i][k],quick(a[i],k));
    rb(i,1,q){
        int l,r,d;
        scanf("%d%d%d",&l,&r,&d);
        int len=r-l+1;
        int s=1ll*len*(len-1)/2%MOD*d%MOD;
        int sum=(pws[r][1]+MOD-pws[l-1][1])%MOD;
        add(sum,MOD-s);
        s=1ll*sum*quick(len,MOD-2)%MOD;
        bool ok=1;
        rb(k,2,10){
            sum=(pws[r][k]+MOD-pws[l-1][k])%MOD;
            int tmp=0;
            rb(j,0,k){
                add(tmp,1ll*quick(s,j)*comb[k][j]%MOD*quick(d,k-j)%MOD*pw[len][k-j]%MOD);
            }
            ok&=(tmp==sum);
        }
        if(ok)
        puts("Yes");
        else
        puts("No");
    }
    return 0;
}