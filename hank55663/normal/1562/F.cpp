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
#define MXN 3000000
vector<int> prime;
int isprime[200005];
int check(LL x){
    int Max=-1;
    for(auto it:prime){
        if(x%it==0)Max=max(Max,it);
    }
    return Max;
}
LL val[505][505];
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    if(n*1ll*(n-1)/2<=n+5000){
        for(int i = 1;i<=n;i++){
            LL gcd=0;
            for(int j = 1;j<=n;j++){
                
                if(j!=i){
                    if(j>i){
                    printf("? %d %d\n",i,j);
                    fflush(stdout);
                    }
                    LL x;
                    if(j>i){
                    scanf("%lld",&x);
                    val[i][j]=x;
                    }
                    else{
                        x=val[j][i];
                        
                    }
                    
                    gcd=__gcd(gcd,x);
                }
            }
            a[i]=gcd;
        }
        if(n==3&&a[3]%2==0&&a[1]%2==0&&a[2]%2==0){
            if(a[3]>a[1]&&a[3]>a[2])a[3]/=2;
            else if(a[1]>a[3]&&a[1]>a[2])a[1]/=2;
            else if(a[2]>a[1]&&a[2]>a[3])a[2]/=2;
        }
        printf("!");
        for(int i = 1;i<=n;i++)printf(" %d",a[i]);
        printf("\n");
        fflush(stdout);
    }
    else{
        set<pii> s;
        pii pp;
        int Max=0;
        for(int i = 1;i<=550;i++){
            int a=rand()%n+1,b=rand()%n+1;
            while(true){
                a=rand()%n+1,b=rand()%n+1;
                if(a>b)swap(a,b);
                if(a==b)continue;
                if(s.find(mp(a,b))==s.end())break;
            }
            printf("? %d %d\n",a,b);
            fflush(stdout);
            LL x;
            scanf("%lld",&x);
            int M=check(x);
            if(M!=-1){
                if(M>Max){
                    Max=M;
                    pp=mp(a,b);
                }
            }
        }
        int x=pp.x+1;
        if(x==pp.y){
            if(x+1==n)x=x-2;
            else x++;
        }
        printf("? %d %d\n",pp.x,x);
        fflush(stdout);
        LL xxx;
        scanf("%lld",&xxx);
        int xx;
        if(xxx%Max==0)xx=pp.x;
        else xx=pp.y;
        LL a[100005];
        for(int i = 1;i<=n;i++){
            if(i==xx)a[i]=Max;
            else{
                printf("? %d %d\n",i,xx);
                fflush(stdout);
                LL x;
                scanf("%lld",&x);
                a[i]=x/Max;
            }
        }
        printf("!");
        for(int i = 1;i<=n;i++)printf(" %lld",a[i]);printf("\n");
        fflush(stdout);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 2;i<=200000;i++){
        if(!isprime[i]){
            prime.pb(i);
            for(int j = i*2;j<=200000;j+=i)isprime[j]=1;
        }
    }
    while(t--){
        solve();
    }
    return 0;
}
/*
100
5 6
9 10 7 5
4 4 4 9
1 2
4 5
3 5
2 3
1 4
1 5

110111
*/