#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define clr(x,k) memset(x,k,sizeof(x))

int col[200];//
int row[200];//

char s[105][105];
int r,c;
int main(){
    //freopen("330C.in","r",stdin);
    int n;
    scanf("%d",&n);
    r=c=0;
    getchar();
    for(int i=1;i <= n;i++)
        gets(s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j = 1;j<=n;j++){
            if(s[i][j]=='E'){
                row[i]++,col[j]++;
                if(row[i]==n) r=1;
                if(col[j]==n) c=1;
                if(r&&c){
                    puts("-1");
                    return 0;
                }
            }
        }
    if(r)
        for(int j=1;j<=n;j++){
            for(int i = 1;i<=n;i++){
                if(s[i][j]=='.'){
                    printf("%d %d\n",i,j);
                    break;
                }
            }
        }
    else{
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(s[i][j]=='.'){
                    printf("%d %d\n",i,j);
                    break;
                }
    }
    return 0;
}