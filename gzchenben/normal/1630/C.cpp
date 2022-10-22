#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200005],lst[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        lst[a[i]]=i;
    }
    int Times=0,To=1,Nxt=2;
    for(int i=1;i<=n;i++)
    {
        Nxt=max(Nxt,lst[a[i]]);
        if(i==To)
        {
            Times++;
            To=Nxt;
            Nxt++;
        }
    }
    printf("%d\n",n-Times);
}