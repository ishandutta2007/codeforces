#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
LL cal(LL a,LL b,int now){
    if(a<0||b<0)return 0;
    if(now==-1)return 1;
    int val=1<<now;
    if(a-val>=val&&b-val>=val){
        return cal(a,b,now-1)*3;
    }
    if(a-val>=val){
        return cal(a,b,now-1)*2+cal(a,b-val,now-1);
    }
    if(b-val>=val){
        return cal(a,b,now-1)*2+cal(a-val,b,now-1);
    }
    return cal(a-val,b,now-1)+cal(a,b-val,now-1)+cal(a,b,now-1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d %d",&l,&r);
        if(l==0){
            printf("%lld\n",cal(r,r,30)-2*cal(r,l,30)+cal(l,l,30)+r+r+1);
        }
        else{
            l--;
            printf("%lld\n",cal(r,r,30)-2*cal(r,l,30)+cal(l,l,30));
        }
    }
}