#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 1005
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int ok[20][30];
    char c[15][30];
    MEM(ok);
    for(int i = 0;i<n;i++)scanf("%s",c[i]);
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            int check=1;
            if(c[i][j]=='*'){
                int tot=0;
                for(int a=1;a<=k&&i-a>=0&&j+a<m&&j-a>=0;a++){
                    if(c[i-a][j-a]=='*'&&c[i-a][j+a]=='*');
                    else check=0;
                    tot++;
                }
                if(tot<k)check=0;
                if(check){
                  //  printf("%d %d\n",i,j);
                    for(int a=0;i-a>=0&&j+a<m&&j-a>=0;a++){
                        if(c[i-a][j-a]=='*'&&c[i-a][j+a]=='*')ok[i-a][j-a]=ok[i-a][j+a]=1;
                        else break;
                    }
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(c[i][j]=='*'){
                if(!ok[i][j]){
                  //  printf("%d %d\n",i,j);
                    printf("NO\n");
                    return;
                }
            }
        }
    }
    printf("YES\n");
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*

*/