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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL a[755];
    for(int i = 1;i<=n;i++){
        //a[i]=-1e9;
        scanf("%lld",&a[i]);
    }
    vector<LL> v;
    for(int t = 0;t<=n;t++){
        LL Max=1e15,Min=-1;
        while(Max>Min+1){
            LL mid=(Max+Min)/2;
            priority_queue<LL,vector<LL>,greater<LL> > pq;
            LL sum=0;
            LL cnt=0;
            for(int i =1;i<=n;i++){
                sum+=a[i];
                pq.push(a[i]);
                if(sum<-mid){
                    cnt++;
                    sum-=pq.top();
                    pq.pop();
                }
            }
            if(cnt>t){
                Min=mid;
            }
            else{
                Max=mid;
            }
        }
      //  printf("%lld\n",-Max);
        v.pb(-Max);
    }
    while(m--){
        LL x;
        scanf("%lld",&x);
        printf("%d\n",lower_bound(v.begin(),v.end(),-x)-v.begin());
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */