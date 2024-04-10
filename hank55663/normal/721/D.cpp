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
#define MXN 300005
#define next Next
#define index Index
int main(){
    LL n,k,x;
    scanf("%lld %lld %lld",&n,&k,&x);
    LL a[200005];
    LL Min=1e9+1,Mini;
    int cnt=0;
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<0)
        cnt++;
        if(Min>abs(a[i])){
            Mini=i;
            Min=abs(a[i]);
        }
    }
    if(cnt%2==0&&(Min+x)/x>k){
        if(a[Mini]>=0){
            a[Mini]-=x*k;
        }
        else{
            a[Mini]+=x*k;
        }
    }
    else{
        if(cnt%2==0){
            if(a[Mini]>=0){
                int num=(Min+x)/x;
                a[Mini]-=x*num;
                k-=num;
            }
            else{
                int num=(Min+x)/x;
                a[Mini]+=x*num;
                k-=num;
            }
        }
        priority_queue<pll,vector<pll>,greater<pll> > pq;
        for(int i=0;i<n;i++){
            pq.push(mp(abs(a[i]),i));
        }
        for(int i = 0;i<k;i++){
            pll p=pq.top();
            pq.pop();
            if(a[p.y]>=0){
                a[p.y] += x;
            }
            else{
                a[p.y] -= x;
            }
            pq.push(mp(abs(a[p.y]),p.y));
        }
    }
    for(int i = 0;i<n;i++){
        printf("%lld ",a[i]);
    }
    printf("\n");
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */