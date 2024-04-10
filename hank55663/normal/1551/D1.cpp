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
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    if(n%2==0&&m%2==0){
        if(k%2==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
    else if(n%2==0){
        if(k%2==0&&n*m/2-k>=n/2)printf("YES\n");
        else printf("NO\n");
    }
    else if(m%2==0){
        k-=m/2;
        if(k>=0&&k%2==0)printf("YES\n");
        else printf("NO\n");
    }  

}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
*/