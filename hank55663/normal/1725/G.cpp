#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
void solve(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("3\n");
    }
    else{
        n+=2;
        LL Max=2*n+1,Min=1;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
            int sum=(mid+1)/2+mid/4;
            if(sum>=n)Max=mid;
            else Min=mid;
        }
        printf("%lld\n",Max);
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
*/