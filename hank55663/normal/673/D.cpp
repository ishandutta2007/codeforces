#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(m<=n||n==4)
        printf("-1\n");
    else{
        int ans[1005];
        ans[0]=a;
        ans[1]=c;
        ans[n-2]=d;
        ans[n-1]=b;
        int l=2;
        for(int i=1;i<=n;i++)
            if(i!=a&&i!=b&&i!=c&&i!=d)
            ans[l++]=i;
        printf("%d",ans[0]);
        for(int i=1;i<n;i++)
            printf(" %d",ans[i]);
        printf("\n");
        swap(ans[0],ans[1]);
        swap(ans[n-1],ans[n-2]);
        printf("%d",ans[0]);
        for(int i=1;i<n;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
}