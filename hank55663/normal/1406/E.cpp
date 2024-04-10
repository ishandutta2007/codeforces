#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> p;
int isprime[100005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 2;i<100005;i++){
        if(isprime[i]==0){
            p.pb(i);
           // if(i>50000)cnt++;
            for(int j = i;j<100005;j+=i){
                isprime[j]=1;
            }
        }
    }
    int ok[100005];
    int cnt=0;
    for(int i = 1;i<=n;i++){
        ok[i]=1;
        cnt++;
    }
    int l=0;
    LL now=1;
    vector<int> pp;
    int fi=0;
    for(int i=0;now*p[i]<=n;i++){
        int x=0;
        for(int j = p[i];j<=n;j+=p[i]){
            if(ok[j])x++,cnt--;
            ok[j]=0;
        }
        printf("B %d\n",p[i]);
        fflush(stdout);
        int y;
        scanf("%d",&y);
        if(y!=x){
            pp.pb(p[i]);
            now*=p[i];
            if(!fi){
                for(int j=l;j<i;j++){
                    printf("A %d\n",p[j]);
                    fflush(stdout);
                    int aa;
                    scanf("%d",&aa);
                    if(aa){
                        pp.pb(p[j]);
                        break;
                    }
                }
                fi=1;
            }
        }
        if(!fi&&i-l>=100){
            printf("A 1\n");
            fflush(stdout);
            int aa;
            scanf("%d",&aa);
            if(aa!=cnt){
                for(int j=l;j<=i;j++){
                    printf("A %d\n",p[j]);
                    fflush(stdout);
                    int aa;
                    scanf("%d",&aa);
                    if(aa){
                        pp.pb(p[j]);
                        break;
                    }
                }
                fi=1;
            }
            l=i+1;
        }
    }
    if(!fi){
        printf("A %d\n",1);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==1){
            printf("C 1\n");
            fflush(stdout);
        }
        else{
            for(int i = l;;i++){
                printf("A %d\n",p[i]);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                if(x){
                    LL ans=p[i];
                    while(ans*p[i]<=n){
                        printf("A %lld\n",ans*p[i]);
                        fflush(stdout);
                        int x;
                        scanf("%d",&x);
                        if(!x)break;
                        ans*=p[i];
                    }
                    printf("C %lld\n",ans);
                    fflush(stdout);
                    return;
                }
            }
        }
    }
    else{
        for(auto it:pp){
            while(now*it<=n){
                printf("A %lld\n",now*it);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                if(!x)break;
                now*=it;
            }
        }
        printf("C %lld\n",now);
        fflush(stdout);
        return;
    }
}

int main(){
    int t=1;
 //   scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/