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
const int MAXN=2e5+1;
void solve(){
    int a,b;
    scanf("%d%d",&a,&b);
    int n=a+b;
    map<int,int> ans;
    int A,B;
    A=n/2;
    B=n-A;
    rb(x,0,A){
        int y_=x-b+B;
        int y__=x-a+B;
        if(y_>=0&&y_<=B) ans[x+y_]=1;
        if(y__>=0&&y__<=B) ans[x+y__]=1;
    }
    printf("%d\n",int(ans.size()));
    for(auto ite=ans.begin();ite!=ans.end();ite++){
        printf("%d ",ite->FIR);
    }
    puts("");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();    
    return 0;
}