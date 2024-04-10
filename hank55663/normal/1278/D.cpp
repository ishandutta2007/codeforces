
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
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int val[1000005];
int S[1000005];
void add(int x,int k){
    for(int i=x;i<1000005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    LL res=0;
    for(int i=x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
LL sum[1000005];
LL myrand(){
    return (((LL)rand()<<40)+((LL)rand()<<20)+rand());
}
int main(){
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("YES\n");
        return 0;
    }
    pii p[500005];
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        val[x]++;
        val[y]--;
        LL a=myrand();
        sum[x]^=a;
        sum[y]^=a;
    }
    set<LL> s;
    s.insert(0);
    for(int i = 1;i<2*n;i++){
        sum[i]^=sum[i-1];
        if(s.find(sum[i])!=s.end()){
            printf("NO\n");
            return 0;
        }
        s.insert(sum[i]);
    }
    sort(p+1,p+n+1);
    LL tot=0;
    int tmp=0;
    for(int i = 1;i<=2*n;i++){
      //  printf("%d ",val[i]);
        if(val[i]==1)tot+=tmp;
      //  printf("%lld\n",tot);
        tmp+=val[i];
        if(i!=2*n&&tmp==0){
            printf("NO\n");
            return 0;
        }
    }
    for(int i = n;i>=1;i--){
        tot-=query(p[i].y);
        add(p[i].y,1);
    }
    /*for(int i = 1;i<=n;i++){
      //  printf("%lld\n",sum[p[i].y]^sum[p[i].x-1]);
        if((sum[p[i].y]^sum[p[i].x-1])==0){
            printf("NO\n");
            return 0;
        }
    }*/
   // printf("%lld\n",tot);
    if(tot==n-1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}