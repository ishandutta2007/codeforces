#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    int n,m;
    scanf("%d %d",&n,&m);
    if(n==1){
        printf("Yes\n");
        printf("%d\n",m);
    }
    else if(n==2){
        if(m%2==0){
            printf("Yes\n");
            printf("%d %d\n",m/2,m/2);
        }
        else{
            printf("No\n");
        }
    }
    else if(m<n){
        printf("No\n");
    }
    else{
        int a[100005];
        for(int i = 1;i<=n;i++)a[i]=1,m--;
        if(n%2==1){
            a[n]+=m;
            printf("Yes\n");
            for(int i = 1;i<=n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
        }
        else{
            if(m%2==0){
                a[n-1]+=m/2,a[n]+=m/2;
                printf("Yes\n");
                for(int i = 1;i<=n;i++)printf("%d ",a[i]);
                printf("\n");
            }
            else{
                printf("No\n");
            }
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
6
1 8 4 6 8 10
2 1
3 1
4 3
5 4
6 3
1 2 1
1 3 1
3 4 1
4 5 1
3 6 1
*/