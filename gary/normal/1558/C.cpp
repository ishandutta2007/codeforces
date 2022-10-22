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
const int MAXN=2021+1;
int a[MAXN];
int n;
vector<int> ans;
int rot(int x,int y){
    int len=y-x+1;
    return len;
}
void solve2(){
    if(n==1) return ;
    int posa,posb;
    rb(i,1,n){
        if(a[i]==n-1) posa=i;
        if(a[i]==n) posb=i;
    }
    if(posa<posb){
        ans.PB(posb);
        reverse(a+1,a+1+posb);
        posa=rot(posa,posb);
        ans.PB(posa-1);
        reverse(a+1,a+1+posa-1);
        posb=posa-1;
    }
    else{
        ans.PB(posb);
        reverse(a+1,a+1+posb);
        ans.PB(posa-1);
        reverse(a+1,a+1+posa-1);
        posb=posa-1;
    }
    ans.PB(n);
    reverse(a+1,a+1+n);
    posa=rot(posa,n);
    posb=rot(posb,n);
    ans.PB(posb);
    reverse(a+1,a+1+posb);
    ans.PB(n);
    reverse(a+1,a+1+n);
    n-=2;
    solve2();
}
void solve(){
    ans.clear();
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,1,n){
        if(a[i]%2!=i%2){
            puts("-1");
            return ;
        }
    }
    int xxx=n;
    solve2();
    printf("%d\n",int(ans.size()));
    for(auto it:ans) printf("%d ",it);
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}