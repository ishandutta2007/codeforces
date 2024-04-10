#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 2005
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[105][105];
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
    }
    
    for(int i = 0;i<n-1;i++){
        for(int j =0;j<m-1;j++){
            int cnt=0;
            for(int a=0;a<=1;a++){
                for(int b=0;b<=1;b++){
                    if(c[i+a][b+j]=='1')cnt++;
                }
            }
            if(cnt==3){
                printf("NO\n");
                return;
            }
        }    
    }
    printf("YES\n");
}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/