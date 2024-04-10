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
#define double long double
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int l=1,r=n;
    int tot=n;
    while(l<r){
        int mid=(l+r)/2;
        printf("? %d %d\n",l,mid);
        fflush(stdout);
        int tt=0;
        for(int i = l;i<=mid;i++){
            int x;
            scanf("%d",&x);
            if(x>=l&&x<=mid)tt++;
        }
        if(tt%2==0)l=mid+1;
        else r=mid;
    }
    printf("! %d\n",l);
    fflush(stdout);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/