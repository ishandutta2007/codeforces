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
#define next Next
int main(){
    int n;
    scanf("%d",&n);
    int a[25];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i = 1;i<=12;i++){
        int ok=1;
        int yy=0;
        for(int j = 0;j<n;j++){
            int x=(i+j-1)%12+1;
            if(a[j]!=mon[x]){
                if(x==2&&a[j]==29&&yy==0){
                    yy=1;
                    continue;
                }
                ok=0;
                break;
            }
        }
        if(ok){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}