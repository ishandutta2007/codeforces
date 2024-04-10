#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
int isprime[100005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[205];
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(!isprime[sum]){
        printf("%d\n",n);
        for(int i = 1;i<=n;i++)printf("%d ",i);
        printf("\n");
        return;
    }
    for(int i = 0;i<n;i++){
        if(!isprime[sum-a[i]]){
            printf("%d\n",n-1);
            for(int j = 1;j<=n;j++){
                if((j-1)!=i){
                    printf("%d ",j);
                }
            }
            printf("\n");
            return ;
        }
    }
     for(int i = 0;i<n;i++){
         for(int k = i+1;k<n;k++){
        if(!isprime[sum-a[i]-a[k]]){
            printf("%d\n",n-2);
            for(int j = 1;j<=n;j++){
                if((j-1)!=i&&(j-1)!=k){
                    printf("%d ",j);
                }
            }
            printf("\n");
            return ;
        }
         }
    }
    for(int i = 0;i<n;i++){
         for(int k = i+1;k<n;k++){
             for(int b=k+1;b<n;b++){
                if(!isprime[sum-a[i]-a[k]-a[b]]){
                    printf("%d\n",n-3);
                    for(int j = 1;j<=n;j++){
                        if((j-1)!=i&&(j-1)!=k&&(j-1)!=b){
                            printf("%d ",j);
                        }
                    }
                    printf("\n");
                    return ;
                }
             }
         }
    }
    assert(0);


}
int main(){
    fill(isprime,isprime+100005,1);
    for(int i = 2;i<=100000;i++){
        if(isprime[i])
        for(int j = i*2;j<=100000;j+=i)isprime[j]=0;
    }
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/