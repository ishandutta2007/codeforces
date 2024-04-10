#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
void solve(){
    int n;
    scanf("%d",&n);
    int a[100000];
    int pre[100000];
    map<int,int> m;
    int sta=-1,stb=-1;
    for(int i = 0;i<n-1;i++){
        printf("XOR %d %d\n",i+1,i+2);
        fflush(stdout);
        scanf("%d",&a[i]);
        if(i==0)pre[i]=a[i];
        else pre[i]=pre[i-1]^a[i];
    //    if(m.find(pre[i]))
        if(pre[i]==0)sta=0,stb=i+1;
        else{
            if(m.find(pre[i])==m.end()){
                m[pre[i]]=i;
            }
            else{
                sta=m[pre[i]]+1;
                stb=i+1;
            }
        }
    }
    if(sta==-1){
        int x;
           int ans[100005];
        for(int i = 0;i<n;i++){
            if(pre[i]==1){
                printf("AND %d %d\n",1,i+2);
                fflush(stdout);
                scanf("%d",&x);  
                break;
            }
        }
        for(int i = 0;i<n;i++){
            if(pre[i]==2){
                printf("AND %d %d\n",1,i+2);
                fflush(stdout);
                int y;
                scanf("%d",&y);
                if(y&1)x++;
                break;  
            }
        }
        ans[0]=x;
        for(int i =0;i<n-1;i++)ans[i+1]=ans[0]^pre[i];
        printf("!");
        for(int i = 0;i<n;i++)printf(" %d",ans[i]);
        printf("\n");
        fflush(stdout);
    }
    else{
        int ans[100005];
        printf("AND %d %d\n",sta+1,stb+1);
        fflush(stdout);
        scanf("%d",&ans[sta]);
        if(sta!=0)
        ans[0]=pre[sta-1]^ans[sta];
        for(int i =0;i<n-1;i++)ans[i+1]=ans[0]^pre[i];
        printf("!");
        for(int i = 0;i<n;i++)printf(" %d",ans[i]);
        printf("\n");
        fflush(stdout);

    }
}

int main(){
    int t=1;
 //   scanf("%d",&t);
    while(t--){
        solve();
    }
}