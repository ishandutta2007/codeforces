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
int main(){
    int n,s;
    scanf("%d %d",&n,&s);
    if(n==1){
        if(s==1){
            printf("NO\n");
        }
        else{
            printf("YES\n%d\n%d\n",s,s-1);
        }
        return 0;
    }
    if(n*2>s){
        printf("NO\n");
    }
    else{
        if(n==1){
            printf("YES\n%d\n%d\n",s,s-1);
            return 0;

        }
        printf("YES\n");
        printf("2 ");
        int k=s;
        s-=2;
        for(int i = 1;i<n-1;i++){
            printf("%d ",2);
            s-=2;
        }
        printf("%d\n",s);
        printf("%d\n",k-1);
    }
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/