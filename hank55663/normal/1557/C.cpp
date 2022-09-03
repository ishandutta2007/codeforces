#include<bits/stdc++.h>
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
int mod=1e9+7;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
  /*  int ans=0;
    for(int i = 0;i<(1<<k);i++){
        for(int j = 0;j<(1<<k);j++){
            for(int a=0;a<(1<<k);a++){
                for(int b=0;b<1;b++){
                    if((i&j&a)>=(a^i^j^b)){
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);*/
    if(k==0){
        printf("1\n");
    }
    else if(n%2==0){
        LL ans=f_pow((f_pow(2,n-1)-1),k)%mod;
      //  printf("%lld\n",ans);
        for(int i = 1;i<=k;i++){
            ans+=f_pow(f_pow(2,i-1),n)*f_pow(f_pow(2,n-1)-1,k-i);
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    else{
        LL ans=f_pow((f_pow(2,n-1)+1),k)%mod;
        printf("%lld\n",ans);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

10 10 40000
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 1
*/