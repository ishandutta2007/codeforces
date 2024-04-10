#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 500005
#define rank Rank
void solve(){
    LL n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    LL cnt1=0,cnt2=0;
    LL all2=1,all22=1;
    for(int i = 1;i<=k;i++){
  LL a;
        scanf("%lld",&a);
        if(a>=2*n&&m!=3){
            cnt1+=a/n;
            if(a/n!=2)all2=0;
        }
        if(m==3&&a>=3*n)cnt1+=a/n,all2=0;
        if(a>=2*m&&n!=3){
            cnt2+=a/m;
            if(a/m!=2)all22=0;
        }
        if(a>=3*m&&n==3)cnt2+=a/m,all22=0;
    }
    if(cnt1>=m||cnt2>=n){
        if(cnt2>=n&&(n%2==0||all22==0))
        printf("Yes\n");
        else if(cnt1>=m&&(m%2==0||all2==0)){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    else printf("No\n");
}
int main(){
    int t=1;000;
    scanf("%d",&t);
//    srand(time(NULL));
    while(t--){
        solve();
    }
    
}
/*
*/