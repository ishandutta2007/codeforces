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
vector<int> prime;
int isprime[1005];
LL rrrrr;
int tq=0;
LL query(LL x){
    if(tq==22)assert(0);
    tq++;
    assert(x>=1&&x<=1e18);
    printf("%lld %lld %lld\n",x,rrrrr,__gcd(x,rrrrr));
    return __gcd(x,rrrrr);
}
LL check(LL res){
    LL tot=1;
    printf("%lld\n",rrrrr);
    for(int i = 2;i*i<=rrrrr;i++){
        int cnt=0;
        while(rrrrr%i==0){
            cnt++;
            rrrrr/=i;
        }
        if(cnt){
            printf("%d %d\n",i,cnt);
        }
        tot*=(cnt+1);
    }
    if(rrrrr!=1){
        printf("%d 1\n",rrrrr);
    }
    if(rrrrr!=1)tot*=2;
    printf("%lld %lld\n",tot,res);
    assert(abs(tot-res)<=7||(tot>=(res+1)/2&&tot<=res*2));
}
int main(){
    MEM(isprime);
    for(int i = 2;i<1005;i++){
        if(!isprime[i]){
            prime.pb(i);
            for(int j=i;j<1005;j+=i){
                isprime[j]=1;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        tq=0;
      //  rrrrr=rand()%1000000000+1;
        __int128 res=1;
        LL cntq=0;
        vector<int> p;
        vector<int> tmp;
        for(auto it:prime){
            res*=it;
           // printf("%lld\n",res);
            if(res>1e18){
                res/=it;
              //  printf("\n");
                printf("? %lld\n",(LL)res);
                cntq++;
                fflush(stdout);
                int x;//=query((LL)res);
                scanf("%d",&x);
                for(auto it:tmp){
                    if(x%it==0)p.pb(it);
                }
                if(cntq+(p.size()+1)/2>=22){
                    break;
                }
                tmp.clear();
                res=it;
            }
           // printf("%d ",it);
            tmp.pb(it);
        }
        LL ans=1;
        for(int i = 0;i<p.size();i+=2){
            LL a=1,b=1;
            while(a*p[i]<=1e9)a*=p[i];
            if(p.size()>i+1)
            while(b*p[i+1]<=1e9)b*=p[i+1];
            printf("? %lld\n",a*b);
            cntq++;
            fflush(stdout);
            int x;//=query(a*b);
            scanf("%d",&x);
            int cnt=1;
            while(x%p[i]==0){
                cnt++;
                x/=p[i];
            }
            //printf("!!!%d ",cnt);
            ans*=cnt;
            cnt=1;
            if(p.size()>i+1)
            while(x%p[i+1]==0){
                cnt++;
                x/=p[i+1];
            }
            ans*=cnt;
          //  printf("%d\n",cnt);
           // printf("!!%d",p[i]);
          //  if(p.size()>i+1)printf(" %d",p[i+1]);
           // printf("\n%d\n",cntq);
            if(cntq==22)break;
        }
        
        printf("! %lld\n",max(ans*2,8ll));
        fflush(stdout);
       // check(max(ans*2,8ll));
    }
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/