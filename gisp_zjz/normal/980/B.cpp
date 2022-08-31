#include<bits/stdc++.h>
#define maxn 1050

using namespace std;
char s[4][maxn];
int n,k,d;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<4;i++) for (int j=0;j<n;j++) s[i][j]='.';
    puts("YES"); d=k/2;
    if (d==n-2){
        for (int j=1;j<3;j++)for (int i=1;i<n-1;i++)s[j][i]='#';
    }
    else {
        if(k&1) s[1][n/2]='#';
        if(d&1) s[1][n/2-1]=s[1][n/2+1]='#';
        for (int j=1;j<=d/2;j++)
            for (int i=1;i<3;i++)
                s[i][j]=s[i][n-1-j]='#';
    }
    for (int i=0;i<4;i++) printf("%s\n",s[i]);
    return 0;
}