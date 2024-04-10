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
#define N 262144
int pre[3000005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[300005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]+=1-a[i]+pre[i-1];
    }
    int ans=-1,Maxl,Maxr;
    for(int i = 1;i<=n;i++){
        int l=0,r=i;
        while(l+1<r){
            int mid=(l+r)/2;
            if(pre[i]-pre[mid]<=k)r=mid;
            else l=mid;
        }
        if(pre[i]<=k){
            if(ans<i)ans=i,Maxl=1,Maxr=i;
        }
        else{
            if(ans<i-r)ans=i-r,Maxl=r+1,Maxr=i;
        }
    }
    printf("%d\n",ans);
    for(int i = Maxl;i<=Maxr;i++)a[i]=1;
    for(int i = 1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/