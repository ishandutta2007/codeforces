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
#define MXN 500005
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[505][505];
    for(int i=0;i<n;i++){
        scanf("%s",c[i]);
    }
    int a[505][505];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m-1;j++){
            if(c[i][j]!=c[i][j+1]){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
        }
        if(c[i][m-1]=='B')a[i][m-1]=1;
        else a[i][m-1]=0;
    }
    int b[505][505];
    int tot=0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j]!=a[i+1][j])b[i][j]=1;
            else b[i][j]=0;
            tot+=b[i][j];
        }
    }
    for(int j=0;j<m;j++){
        b[n-1][j]=a[n-1][j];
        tot+=b[n-1][j];
    }
    if(b[n-1][m-1]==1){
        for(int i = 0;i<n-1;i++){
            for(int j = 0;j<m-1;j++){
                if(b[i][j]&&b[i][m-1]&&b[n-1][j]){
                    tot--;
                    printf("%d\n",tot);
                    return;
                }
            }
        }

    }
            printf("%d\n",tot);
}
int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
7
34 38 10
8 32 9
3 7 10
5 13 9
23 40 5
28 34 1
24 26 10
*/