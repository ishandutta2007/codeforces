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
#define ll long long
int main(){
    int n;
    scanf("%d",&n);
    int st;
    srand(time(NULL));
    while(true){
        
        int x=rand()%n+1;
        int y=rand()%n+1;
        while(y==x)y=rand()%n+1;
        printf("? %d %d\n",x,y);
        fflush(stdout);
        int a;
        scanf("%d",&a);
        if(__builtin_popcount(a)<8){
            st=x;
            break;
        }
    }
    vector<int> v;
        int Min=1e9;
        for(int i = 1;i<=n;i++){
            if(i!=st)
            v.pb(i);
        }
    while(true){

        vector<int> v2;
        int x=(1<<20)-1;
        for(auto it:v){
            printf("? %d %d\n",it,st);
            fflush(stdout);
            int a;
            scanf("%d",&a);
            x&=a;
            if(a<Min){
                Min=a;
                v2.clear();
            }
            if(a==Min){
                v2.pb(it);
            }
        }
        if(x==0){
            break;
        }
        if(v2.size()==1){
            st=v2.back();
            break;
        }
        st=v2.back();
        v2.pop_back();
        swap(v,v2);
    }
    int ans[3000];
    for(int i = 1;i<=n;i++){
        if(st==i)ans[i]=0;
        else{
            printf("? %d %d\n",i,st);
            fflush(stdout);
            scanf("%d",&ans[i]);
        }
    }
    printf("!");
    for(int i = 1;i<=n;i++){
        printf(" %d" ,ans[i]);
    }
    printf("\n");
    fflush(stdout);
}