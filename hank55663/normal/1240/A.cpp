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
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        int p[200005];
        for(int i = 0;i<n;i++)
            scanf("%d",&p[i]);
        sort(p,p+n);
        reverse(p,p+n);
        int x,a,y,b;
        scanf("%d %d %d %d",&x,&a,&y,&b);
        if(x>y){
            swap(x,y);
            swap(a,b);
        }
        LL toge=(LL)a*b/__gcd(a,b);
        LL k;
        scanf("%lld",&k);
        int Max=n+1,Min=0;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
            int aabb=mid/toge;
            int aa=mid/a-aabb;
            int bb=mid/b-aabb;
            LL tot=0;
            for(int i = 0;i<aabb;i++)
                tot+=p[i]/100*(x+y);
            for(int i = aabb;i<aabb+bb;i++){
                tot+=p[i]/100*y;
            }
            for(int i=aabb+bb;i<aabb+aa+bb;i++)
                tot+=p[i]/100*x;
            //printf("%d %d %d %d %d\n",mid,tot,aabb,aa,bb);
            if(tot>=k){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        if(Max==n+1)Max=-1;
        printf("%d\n",Max);
    }
    return 0;
}