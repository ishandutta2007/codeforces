#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k,z;
        scanf("%d %d %d",&n,&k,&z);
        int a[100005];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        LL ans=0;
        k++;
        for(int i = 0;i<=z;i++){
            if(k-i*2<=0)continue;
            LL sum=0;
            vector<int> v;
            for(int j =0;j<k-i*2;j++){
                if(j!=k-i*2)
                v.pb(a[j]+a[j+1]);
                sum+=a[j];
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            sum+=v[0]*i;
            //for(int j = 0;j<i&&j<v.size();j++)sum+=v[j];
            ans=max(ans,sum);
        }
        printf("%lld\n",ans);
    }
}