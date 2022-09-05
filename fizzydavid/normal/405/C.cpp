#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
int q,n;
bool a[1111][1111];
bool ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)ans^=a[i][i];
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int x;scanf("%d",&x);
        if(x==3)printf("%d",ans);
        else {int y;scanf("%d",&y);ans^=1;}
    }
 	return 0;
}