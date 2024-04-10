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
    if(n==1)printf("a");
    else if(n%2==0){
        for(int i = 0;i<n/2;i++)printf("a");
        printf("b");
        for(int i = 0;i<n/2-1;i++)printf("a");
    }
    else{
        n--;
        for(int i = 0;i<n/2;i++)printf("a");
        printf("b");
        for(int i = 0;i<n/2-1;i++)printf("a");
        printf("c");
    }
    printf("\n");
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