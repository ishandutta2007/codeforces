#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[1000006];
int cnt[1000006];
int tot[1000006];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=m)
        cnt[a[i]]++;
    }
    int Max=0,Maxi=1;
    for(int i = 1;i<=m;i++){
        for(int j=i;j<=m;j+=i){
            tot[j]+=cnt[i];
        }
        if(tot[i]>Max){
            Max=tot[i];
            Maxi=i;
        }
    }
    printf("%d %d\n",Maxi,Max);
    for(int i = 1;i<=n;i++){
        if(Maxi%a[i]==0){
            printf("%d ",i);
        }
    }
    printf("\n");
}