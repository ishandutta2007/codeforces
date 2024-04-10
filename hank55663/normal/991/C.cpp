#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    LL n;
    scanf("%lld",&n);
    LL Min=0,Max=n;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        LL k=n;
        LL sum=0;
        while(k){
            sum+=mid;
            k-=mid;
            k-=k/10;
            if(sum*2>=n||(sum+k)*2<n){
                break;
            }
        }
        if(sum*2>=n)
        Max=mid;
        else
        Min=mid;
    }
    printf("%lld\n",Max);
    return 0;
}