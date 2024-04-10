#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    int val[300005];
    LL mask[300005];
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d %lld",&val[i],&mask[i]);
        sum+=val[i];
    }
    if(sum<0){
        for(int i=0;i<n;i++)
            val[i]=-val[i];
    }
    LL ans=0;
    for(int j = 0;j<62;j++){
        LL sum=0;
        for(int i = 0;i<n;i++){
            if(mask[i]==(1ll<<j)){
                sum+=val[i];
            }
        }
        if(sum>0){
            ans+=(1ll<<j);
            for(int i =0;i<n;i++){
                if(mask[i]&(1ll<<j)){
                    val[i]=-val[i];
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(mask[i]&(1ll<<j)){
                mask[i]-=(1ll<<j);
            }
        }
    }
    printf("%lld\n",ans);
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i

*/