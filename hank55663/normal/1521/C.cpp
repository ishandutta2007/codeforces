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
void solve(){
    int n;
    scanf("%d",&n);
    if(n==3){
        int a[4];
        MEMS(a);
        for(int i = 2;i<=n;i++){
            printf("? 2 %d %d %d\n",i,1,1);
            fflush(stdout);
            int x;
            scanf("%d",&x);
            if(x==1){
                a[i]=1;
                break;
            }
        }
        if(a[2]==-1&&a[3]==-1)a[1]=1;
        vector<int> v;
        for(int i = 1;i<=3;i++)
        if(a[i]==-1)v.pb(i);
        printf("? 2 %d %d %d\n",v[0],v[1],2);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==2)a[v[0]]=2,a[v[1]]=3;
        else a[v[0]]=3,a[v[1]]=2;
        printf("! %d %d %d\n",a[1],a[2],a[3]);
        fflush(stdout);
        return;
    }
    int a[10005];
    for(int i = 1;i<n;i+=2){
        printf("? 1 %d %d %d\n",i,i+1,n-1);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        printf("? 2 %d %d %d\n",i,i+1,1);
        fflush(stdout);
        int y;
        scanf("%d",&y);
        if(x==n||y==1){
            a[i]=y;
            a[i+1]=x;
        }
        else{
            printf("? 2 %d %d %d\n",i,i+1,x-1);
            fflush(stdout);
            int z;
            scanf("%d",&z);
            if(z==x)a[i]=x,a[i+1]=y;
            else a[i+1]=x,a[i]=y;
        }
    }
   //  printf("!");
   // for(int i = 1;i<=n;i++)printf(" %d",a[i]);
   // printf("\n");
    if(n%2==1){
        printf("? 1 %d %d %d\n",n,n-1,n-1);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        printf("? 2 %d %d %d\n",n,n-1,1);
        fflush(stdout);
        int y;
        scanf("%d",&y);
        if(x==a[n-1])a[n]=y;
        else a[n]=x;
    }
    vector<int> v1,v2;
    for(int i = 1;i<=n;i++){
        if(a[i]==2)v1.pb(i);
        if(a[i]==n-1)v2.pb(i);
    }
    if(v1.size()==2){
        printf("? 1 %d %d %d\n",v1[0],v1[1],1);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x!=1)a[v1[0]]=1;
        else a[v1[1]]=1;
    }
    if(v2.size()==2){
        printf("? 1 %d %d %d\n",v2[0],v2[1],n-1);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x!=n)a[v2[0]]=n;
        else a[v2[1]]=n;
    }
    printf("!");
    for(int i = 1;i<=n;i++)printf(" %d",a[i]);
    printf("\n");
    fflush(stdout);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/