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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index

int f[205];
void KMP(char *c){
    int j=-1;
    f[0]=-1;
    for(int i = 1;c[i]!=0;i++){
        while(j!=-1&&c[i]!=c[j+1])j=f[j];
        if(c[i]==c[j+1])j++;
        f[i]=j;
    }
}
int vis[205];
void solve(){
    MEM(vis);
    int n;
    scanf("%d",&n);
    char c[205];
    scanf("%s",c+1);
    int p[205];
    LL lcm=1;
    for(int i =1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i = 1;i<=n;i++){
        int now=i;
        if(!vis[now]){
            char cc[555];
            int it=0;
            do{
                cc[it++]=c[p[now]];
                now=p[now];
                //printf("%c",cc[it-1]);
                vis[now]=1;
            }while(now!=i);
           // printf("\n");
            cc[it]=0;
            KMP(cc);
            int d=it-1-f[it-1];
            LL len=it;
           // printf("%d %d\n",d,len);
            if(it%d==0){
                len=d;
            }
            lcm=lcm*len/__gcd(lcm,len);
        }
    }
    printf("%lld\n",lcm);
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}