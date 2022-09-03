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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int a[100005];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        int ok=0;
        for(int i = 0;i<n;i++){
            if(a[i]==k)ok=1;
            if(a[i]>=k)a[i]=1;
            else a[i]=0;
        }
        if(!ok){
            printf("NO\n");
        }
        else{
            ok=0;
            for(int i = 0;i<n-1;i++){
                if(a[i]&&a[i+1])ok=1;
            }
            for(int i = 1;i<n-1;i++){
                if(a[i-1]&&a[i+1])ok=1;
            }
            if(n==1)ok=1;
            if(ok){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}