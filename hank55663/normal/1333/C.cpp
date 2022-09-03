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
    int n;
    scanf("%d",&n);
    int a[200005];
    map<LL,int> m;
    m[0]=0;
    LL ans=0;
    LL pre=0;
    int Max=-1;
    for(int i = 1 ; i<=n;i++){
        scanf("%d",&a[i]);
        pre+=a[i];
        if(m.find(pre)==m.end()){
            //ans+=i;
        }
        else{
            Max=max(Max,m[pre]);
           // ans+=i-m[pre]-1;
        }
        ans+=i-Max-1;
        m[pre]=i;
    }
    printf("%lld\n",ans);
}
/*

*/