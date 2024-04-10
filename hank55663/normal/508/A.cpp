#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
main(){
    bool a[1001][1001];
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            a[i][j]=false;
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        a[x][y]=true;
        if(a[x-1][y-1]&&a[x][y-1]&&a[x-1][y]&&!ans)
            ans=i;
        else if(x<m&&a[x+1][y]&&a[x][y-1]&&a[x+1][y-1]&&!ans)
            ans=i;
        else if(y<n&&a[x-1][y]&&a[x][y+1]&&a[x-1][y+1]&&!ans)
            ans=i;
        else if(x<m&&y<n&&a[x+1][y+1]&&a[x+1][y]&&a[x][y+1]&&!ans)
            ans=i;
    }
    printf("%d\n",ans);
    return 0;
}