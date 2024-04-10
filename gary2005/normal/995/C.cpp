/**
 *    author:  gary
 *    created: 02.08.2022 08:58:28
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+10;
int n,x[MAXN],y[MAXN],id[MAXN],c[MAXN];
const LL limit=1500000ll*1500000;
LL dis(LL px,LL py){
    return px*px+py*py;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>x[i]>>y[i],id[i]=i;
    SRAND;
    while (true){
        shuffle(id+1,id+1+n,rng);
        LL px,py;
        px=py=0;
        rb(i_,1,n){
            int i=id[i_];
            if(dis(px+x[i],py+y[i])>dis(px-x[i],py-y[i])){
                c[i]=-1;
                px-=x[i];
                py-=y[i];
            }
            else{
                c[i]=1;
                px+=x[i];
                py+=y[i];
            }
        }
        if(dis(px,py)<=limit) break;
    }
    rb(i,1,n) cout<<c[i]<<' ';
    cout<<endl;
    return 0;
}