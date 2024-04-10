/**
 *    author:  gary
 *    created: 03.10.2021 19:22:50
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
const int MAXN=101;
int a[MAXN],b[MAXN],n;
set<int> sab[MAXN],sb[MAXN];
vector<mp> da[MAXN],db[MAXN];
int quick(int A,int B){
    if(B==0) return 1;
    int tmp=quick(A,B>>1);
    tmp=1ll*tmp*tmp%MOD;
    if(B&1) tmp=1ll*tmp*A%MOD;
    return tmp;
}
vector<mp> d(int x){
    vector<mp> v;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            v.PB(II(i,0));
            while(x%i==0) v.back().SEC++,x/=i;
        }
    }
    if(x!=1) v.PB(II(x,1));
    return v;
}
bool check(int i,int x){
    if(x%a[i]) return false;
    x/=a[i];
    while(x!=1){
        if(x%b[i]) return false;
        x/=b[i];
    }
    return true;
}
bool check(int i,map<int,int> M){
    for(auto it:da[i]){
        M[it.FIR]-=it.SEC;
        if(M[it.FIR]<0) return false;
    }
    int cnt=-1;
    for(auto it:db[i]){
        if(M[it.FIR]%it.SEC) return false;
        if(cnt==-1||cnt==M[it.FIR]/it.SEC) cnt=M[it.FIR]/it.SEC;
        else return false;
        M[it.FIR]=0;
    }
    for(auto ite=M.begin();ite!=M.end();ite++) if(ite->SEC){
        return false;
    }
    return true;
}
int put(map<int,int> M){
    int rest=1;
    for(auto ite=M.begin();ite!=M.end();ite++) rb(j,1,ite->SEC) rest=1ll*rest*ite->FIR%MOD;
    return rest;
}
void solve1(){
    int rest=INF;
    rb(i,1,n){
        bool ok=1;
        rb(j,1,n){
            ok&=check(j,a[i]);
        }
        if(ok){
            cout<<a[i]<<endl;
            exit(0);
        }
    }
}
LL exGcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL r = exGcd(b,a%b,x,y);
    LL t = x; x = y;
    y = t-a/b*y;
    return r;
}
void solve2(){
    map<int,int> M;
    for(auto it:da[1]) M[it.FIR]+=it.SEC;
    for(auto it:db[1]) M[it.FIR]+=it.SEC;
    rb(T,1,3000){
        bool ok=1;
        rb(i,1,n) ok&=check(i,M);
        if(ok){
            printf("%d\n",put(M));
            exit(0);
        }
        for(auto it:db[1]) M[it.FIR]+=it.SEC;
    }
}
LL mygcd(LL A,LL B){
    if(B==0) return A;
    return mygcd(B,A%B);
}
vector<mp> dgb[MAXN],dga[MAXN];
int a_[MAXN],b_[MAXN];
void solve3(){
    rb(i,1,n){
        int g=0;
        for(auto it:db[i]){
            g=__gcd(g,it.SEC);
        }
        for(auto it:db[i]){
            dgb[i].PB(II(it.FIR,it.SEC/g));
        }
        map<int,int> M;
        for(auto it:da[i]) M[it.FIR]=it.SEC;
        int bst=INF;
        for(auto it:dgb[i]) check_min(bst,M[it.FIR]/it.SEC);
        for(auto it:dgb[i]) M[it.FIR]-=it.SEC*bst;
        for(auto ite=M.begin();ite!=M.end();ite++) if(ite->SEC) dga[i].PB(*ite);
        a_[i]=bst;
        b_[i]=g;
    }
    rb(i,1,n) if(dga[i]!=dga[1]||dgb[i]!=dgb[1]) return ;
    LL now=a_[1];
    LL atime=b_[1];
    map<int,int> Mm;
    for(auto it:dga[1]) Mm[it.FIR]=it.SEC;
    int A1=put(Mm);
    Mm.clear();
    for(auto it:dgb[1]) Mm[it.FIR]=it.SEC;
    int A2=put(Mm);
    rb(i,1,n) a[i]=a_[i],b[i]=b_[i];
    rb(i,1,n){
        // now + atime*x = b[i] * y + a[i]
        // atime*x - b[i]*y = a[i]-now
        LL tmp=a[i]-now;
        LL g=mygcd(atime,b[i]);
        if(tmp%g) return ;
        g=tmp/g;
        LL x,y;
        LL l = atime/mygcd(atime,b[i])*b[i];
        exGcd(atime,b[i],x,y);
        x*=g;
        y*=g;
        // x + = l/atime , y - = l/b[i]
        LL z=l/atime;
        x%=z;
        if(x<0) x+=z;
        now+=atime*x;
        atime=l;
    }
    printf("%lld\n",1ll*A1*quick(A2,now%(MOD-1))%MOD);
    exit(0);
}
int main(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d%d",&a[i],&b[i]);
    solve1();
    rb(i,1,n){
        da[i]=d(a[i]);
        db[i]=d(b[i]);
        for(auto it:da[i]) sab[i].insert(it.FIR);
        for(auto it:db[i]) sab[i].insert(it.FIR),sb[i].insert(it.FIR);
    }
    rb(i,1,n) if(sab[i]!=sab[1]) {
        puts("-1");
        return 0;
    }
    solve2();
    solve3();
    puts("-1");
    return 0;
}