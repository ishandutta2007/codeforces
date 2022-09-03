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
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        LL a,b,m;
        scanf("%lld %lld %lld",&a,&b,&m);
        if(a==b){
            printf("1 %lld\n",a);
        }
        else if(b-a<=m){
            printf("2 %lld %lld\n",a,b);
        }
        else{
            for(int i = 1;;i++){
                LL lower=(a+1)*(1ll<<i),upper=(a+m)*(1ll<<i);
              //  printf("%lld %lld\n",lower,upper);
                if(lower>b){
                    printf("-1\n");
                    break;
                }
                else if(b<=upper){
                    printf("%d",i+2);
                    b-=lower;
                    LL x[50];
                    for(int j=0;j<i-1;j++){
                        x[j]=min(b/(1ll<<(i-j-1)),m-1);
                        b-=x[j]*(1ll<<(i-j-1));
                    }
                    x[i-1]=b/2;
                    x[i]=b-b/2;
                    LL sum=a;
                    printf(" %lld",a);
                    for(int j=0;j<=i;j++){
                        printf(" %lld",sum+x[j]+1);
                        sum=sum*2+x[j]+1;
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }

}