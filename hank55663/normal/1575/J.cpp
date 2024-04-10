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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[1005][1005];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        int nowx=1,nowy=x;
        while(nowx!=n+1){
            if(a[nowx][nowy]==3){
                a[nowx][nowy]=2;
                nowy--;
            }
            else if(a[nowx][nowy]==1){
                a[nowx][nowy]=2;
                nowy++;
            }
            else{
                nowx++;
            }
        }
        printf("%d ",nowy);
    }
    printf("\n");
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/