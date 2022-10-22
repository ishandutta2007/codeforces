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
int n,a[MAXN];
int bit[MAXN];
void add(int pos){
    while(pos<=n){
        bit[pos]++;
        pos+=pos&-pos;
    }
}
int sum(int pos){
    int s=0;
    while(pos){
        s+=bit[pos];
        pos-=pos&-pos;
    }
    return s;
}
LL work(vector<int> z){
    rb(i,1,n) bit[i]=0;
    LL tmp=0;
    rb(i,1,n){
        tmp+=i-1-sum(z[i-1]);
        add(z[i-1]);
    }
    return tmp;
}
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]),a[i]%=2;
    vector<int> tmp[2];
    rb(i,1,n) tmp[a[i]].PB(i);
    if(max(tmp[0].size(),tmp[1].size())-min(tmp[0].size(),tmp[1].size())>1){
        puts("-1");
        return ;
    }
    vector<int> z;
    LL answer=1e18;
    if(tmp[0].size()>=tmp[1].size()){
        rep(i,n){
            z.PB(tmp[i&1][i/2]);
        }
        check_min(answer,work(z));
    }
    swap(tmp[0],tmp[1]);
    z.clear();
    if(tmp[0].size()>=tmp[1].size()){
        rep(i,n){
            z.PB(tmp[i&1][i/2]);
        }
        check_min(answer,work(z));
    }
    printf("%lld\n",answer);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}