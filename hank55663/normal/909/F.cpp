#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int hihi(int x){
    int y=1;
    while(y<=x){
        y<<=1;
    }
    return y-1;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n%2==0){
        int ans[100005];
        fill(ans,ans+n+1,0);
        for(int i = n;i>=1;i--){
            if(ans[i]==0){
                int x=hihi(i);
                assert(ans[x^i]==0);
                ans[i]=x^i;
                ans[x^i]=i;
            }
        }
        printf("YES\n");
        for(int i = 1;i<=n;i++)
        printf("%d ",ans[i]);
        printf("\n");
    }
    else{
        printf("NO\n");
    }
    if(n<=5||__builtin_popcount(n)==1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        if(n==6){
            printf("3 6 2 5 1 4");
        }
        else{
            printf("7 6 2 5 1 4 3");
            int l=8,r=16;
            for(int i = 8;i<=n;i++){
                if(i==r){
                    l=l*2;
                    r=r*2;
                }
                if(i+1==r||i+1>n)
                printf(" %d",l);
                else
                printf(" %d",i+1);
            }
        }
        printf("\n");
    }
}