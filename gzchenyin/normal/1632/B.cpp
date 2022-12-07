#include<cstdio>
using namespace std;
int n,t,cnt[2];
char a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int tmp=1;
        while(2*tmp<n) tmp=tmp*2;
        for(int i=1;i<tmp;i++) printf("%d ",i);
        printf("%d %d ",0,tmp);
        for(int i=tmp+1;i<n;i++) printf("%d ",i);
        printf("\n");
    }
}