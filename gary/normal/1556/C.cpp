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
const int MAXN=1e3+1;
LL a[MAXN];
int n;
int main(){
    LL answer=0;
    scanf("%d",&n);
    rb(i,1,n) scanf("%lld",&a[i]);
    rb(l,1,n){
        if(l%2==1){
            LL bst,now;
            bst=now=0;
            rb(r,l+1,n){
                if(r%2==0){
                    pair<LL,LL> rang=II(1,a[l]);
                    check_max(rang.FIR,-bst);
                    check_max(rang.FIR,1-now);
                    check_min(rang.SEC,a[r]-now);
                    answer+=max(0ll,rang.SEC-rang.FIR+1);
                }
                if(r%2==0) now-=a[r];
                else now+=a[r];
                check_min(bst,now);
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}