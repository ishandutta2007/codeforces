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
#define KK 500
#define N 100005
#define MXN 2000005
int a[1000005];
int aa[1000005];
LL check(LL k,int n){
    for(int i = 0;i<n;i++)
    aa[i]=a[i];
    LL mid=(k+1)/2;
    int loc=-1;
    LL sum=0;
    vector<pii> tmp;
    LL res=0;
    for(int i = 0;i<n;i++){
        sum+=aa[i];
        if(sum>=mid&&loc==-1){
            loc=i;
        }       
        if(sum>=k){
            tmp.pb(mp(k-(sum-aa[i]),i));
            aa[i]-=k-(sum-aa[i]);
            aa[i]%=k;
            for(auto it:tmp){
                res+=(LL)it.x*abs(it.y-loc);
            }
            tmp.clear();
            sum=0;
            i--;
            loc=-1;
            continue;
        }
        else{
            tmp.pb(mp(aa[i],i));
        }
      //  printf("%d %d\n",loc,res);
    }
  // printf("%d %d\n",k,res);
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum==1){
        printf("-1\n");
        return 0;
    }
    LL ans=1e18;
    for(LL i=2;i*i<=sum;i++){
        if(sum%i==0){
            ans=min(ans,check(i,n));
            ans=min(ans,check(sum/i,n));
        }
    }
    ans=min(ans,check(sum,n));
    printf("%lld\n",ans);
    return 0;
}