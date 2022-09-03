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
#define MXN 2000005
int cp[1005][1005];
int cnt=0;
int query(int a,int b){
    if(cp[a][b]!=-1)return cp[a][b];
    printf("2 1 %d %d\n",a,b);
    fflush(stdout);
    int x;
    if(a<b)x=-1;
    else x=1;
    //scanf("%d",&x);
    cnt++;
    if(x==1)cp[a][b]=1,cp[b][a]=0;
    else cp[a][b]=0,cp[b][a]=1;
    return cp[a][b];
}
bool cmp(const int &a,const int &b){
    return query(a,b);
}
int main(){
    int n;
    scanf("%d",&n);
    int Min=2;
    for(int i=3;i<=n;i++){
        printf("2 1 %d %d\n",Min,i);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==-1)Min=i;
    }
    int a[1005];
    a[0]=1;
    a[1]=Min;
    LL S[1005];
    LL Max=0;
    int Maxi=0;
    for(int i = 2;i<=n;i++){
        if(i!=Min){
            printf("1 1 %d %d\n",Min,i);
            fflush(stdout);
            LL x;
            scanf("%lld",&x);
            S[i]=x;
            if(x>Max){
                Max=x;
                Maxi=i;
            }
        }
    }
    vector<pll> v1,v2;
    for(int i =2;i<=n;i++){
        if(i!=Maxi&&i!=Min){
            printf("2 1 %d %d\n",Maxi,i);
            fflush(stdout);
            int x;
            scanf("%d",&x);
            if(x==1){
                v1.pb(mp(S[i],i));
            }
            else{
                v2.pb(mp(S[i],i));
            }
        }
    }
    sort(v2.begin(),v2.end());
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    printf("0 %d %d",1,Min);
    for(auto it:v2)
        printf(" %lld",it.y);
    printf(" %d",Maxi);
    for(auto it:v1)
        printf(" %lld",it.y);
    printf("\n");
    /*for(int i = 0;i<n;i++)
        printf(" %d",a[i]);
    printf("\n");*/
   // printf("%d\n",cnt);
    fflush(stdout);
    return 0;
}