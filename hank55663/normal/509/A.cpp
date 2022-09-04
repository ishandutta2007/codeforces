#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<string.h>
using namespace std;
main(){
    int t[20][20];
    for(int i=0;i<20;i++)
    {
        t[i][0]=1;
        t[0][i]=1;
    }
    for(int i=1;i<20;i++)
        for(int j=1;j<20;j++)
        t[i][j]=t[i-1][j]+t[i][j-1];
    int n;
    scanf("%d",&n);
    printf("%d",t[n-1][n-1]);
    return 0;
}