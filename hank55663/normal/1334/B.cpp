#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,x;
        scanf("%lld %lld",&n,&x);
        LL a[100005];
        for(int i = 0;i<n;i++){
            //int a;
            scanf("%lld",&a[i]);
            //sum+=a;
        }
        sort(a,a+n);
        reverse(a,a+n);
        int ans=0;
        LL sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum>=x*(i+1)){
                ans=i+1;
            }
        }
        printf("%d\n",ans);
    }
}
/*

*/