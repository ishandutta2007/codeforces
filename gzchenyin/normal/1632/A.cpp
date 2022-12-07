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
        cnt[0]=0,cnt[1]=0;
        for(int i=1;i<=n;i++)
        {
            scanf(" %c",&a[i]);
            cnt[a[i]-'0']++;
        }
        if(cnt[0]>=2 || cnt[1]>=2) printf("NO\n");
        else printf("YES\n");
    }
}