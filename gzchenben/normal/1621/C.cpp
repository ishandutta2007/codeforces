#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,p[100005];
int Ask(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    int tmp=0;
    scanf("%d",&tmp);
    return tmp;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) p[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i]) continue;
            int Fir=Ask(i),tmp=0,lst=Fir;
            while(tmp!=Fir)
            {
                tmp=Ask(i);
                p[lst]=tmp;
                lst=tmp;
            } 
        }
        printf("!");
        for(int i=1;i<=n;i++) printf(" %d",p[i]);
        printf("\n");
        fflush(stdout);
    }
}