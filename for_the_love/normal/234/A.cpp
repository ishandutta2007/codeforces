#include <cstdio>
#include <cstring>
int a[2000];
int i,n;
char ch;
void work(int i,int j)
{
        if (a[j]==1) printf("%d %d\n",j,i); else printf("%d %d\n",i,j);
}
int main()
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        scanf("%d",&n); getchar();
        for (i=1;i<=n;i++)
        {
                scanf("%c",&ch);
                if (ch=='L') a[i]=1; else a[i]=2;
        }
        if (n%4==0)
        {
                for (i=1;i<=n;i=i+4)
                {
                        work(i,i+2); work(i+1,i+3);
                }
        }
        else
        {
                for (i=1;i<=n;i=i+4)
                {
                        if (i+6>n) break;
                        work(i,i+2); work(i+1,i+3);
                }
                i=n-5; work(i,i+3); work(i+1,i+4); work(i+2,i+5);
        }
        return 0;

}