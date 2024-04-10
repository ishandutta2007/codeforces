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
using namespace std;
#define MXN 100005
bool solve(){
    int n;
    scanf("%d",&n);
    char c[305][305];
    int tot=0;
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        for(int j =0;j<n;j++){
            if(c[i][j]!='.')tot++;
        }
    }
    for(int i = 1;i<7;i++){
        char tmp[305][305];
        char cc[10];
        for(int j = 0;j<3;j++){
            if(i&(1<<j))cc[j]='O';
            else cc[j]='X';
        }
        int sum=0;
        for(int j=0;j<n;j++){
            for(int k =0;k<n;k++){
                tmp[j][k]=cc[(j+k)%3];
                if(tmp[j][k]!=c[j][k]&&c[j][k]!='.')sum++;
            }
        }
        if(sum<=tot/3){
            for(int j = 0;j<n;j++){
                for(int k = 0 ;k<n;k++){
                    if(c[j][k]=='.')
                    printf("%c",c[j][k]);
                    else
                    printf("%c",tmp[j][k]);
                }
                printf("\n");
            }
            return true;
        }
    }
    assert(0);
    return true;
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}
/*

2 3
1 3
4 2
2 5
3 5
1 2
5 4
*/