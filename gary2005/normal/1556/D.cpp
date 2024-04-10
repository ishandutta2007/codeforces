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
const int MAXN=1e4+1;
int n,k,b[MAXN];
vector<pair<mp,int> > xo,o,a;
int Xor(int x,int y){
    int O,A;
    cout<<"or "<<x<<" "<<y<<endl;ff;
     cin>>O;
//    O=p[x]|p[y];
    o.PB(II(II(x,y),O));
    cout<<"and "<<x<<" "<<y<<endl;ff;
     cin>>A;
//    A=p[x]&p[y];
    a.PB(II(II(x,y),A));
    xo.PB(II(II(x,y),O-A));
    return O-A;
}
int num[MAXN];
int main(){
    scanf("%d%d",&n,&k);
//    rb(i,1,n) cin>>p[i];
    rb(i,1,n-1) b[i]=Xor(i,i+1);
    Xor(1,3);
    int fuckd=a[0].SEC;
    for(auto it:a) fuckd&=it.SEC;
    int fuckx=xo[0].SEC;
    for(auto it:xo) fuckx|=it.SEC;
    for(int i=1;i<=fuckx;i<<=1){
        if(fuckx&i){
            int A;
            bool ok;
            for(auto it:o){
                if(it.SEC&i);
                else{
                    A=it.FIR.FIR;
                    ok=0;
                }
            }
            for(auto it:a){
                if(it.SEC&i){
                    A=it.FIR.FIR;
                    ok=1;
                }
            }
//            cout<<A<<' '<<ok<<" "<<i<<endl;
            if(ok){
                num[A]|=i;
                int x=i;
                rb(i,A,n-1){
                    if(b[i]&x){
                        ok^=1;
                    }
                    if(ok) num[i+1]|=x;
                }
                ok=1;
                rl(i,A-1,1){
                    if(b[i]&x) ok^=1;
                    if(ok) num[i]|=x;
                }
            }
            else{
                int x=i;
                rb(i,A,n-1){
                    if(b[i]&x){
                        ok^=1;
                    }
                    if(ok) num[i+1]|=x;
                }
                ok=0;
                rl(i,A-1,1){
                    if(b[i]&x) ok^=1;
                    if(ok) num[i]|=x;
                }
            }
        }
    }
    sort(num+1,num+1+n);
    cout<<"finish "<<(num[k]|fuckd)<<endl;ff;
    return 0;
}