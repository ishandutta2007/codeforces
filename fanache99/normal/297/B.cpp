#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],b[100010];
bool cmp(int x,int y){
    if(x>y)
        return true;
    return false;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    if(n>m){
        printf("YES");
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+m+1,cmp);
    for(i=1;i<=n;i++)
        if(a[i]>b[i]){
            printf("YES");
            return 0;
        }
    printf("NO");
    return 0;
}