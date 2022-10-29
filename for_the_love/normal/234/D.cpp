#include <cstdio>
int n,m,tmp,i,num,tmax,tmin,cnt,j,flag,t1,t2;
int mini[20000],maxi[20000],v[20000];
char s[1000];
int max(int a,int b)
{
        if (a>b) return a; else return b;
}
int min(int a,int b)
{
        if (a>b) return b; else return a;
}
int main()
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        scanf("%d%d",&n,&m);
        for (i=1;i<=m;i++)
        {
                scanf("%d",&tmp); v[tmp]=1;
        }
        scanf("%d",&num);
        for (i=1;i<=num;i++)
        {
                scanf("%s",s);
                scanf("%d",&cnt);
                t1=0; t2=0;
                for (j=1;j<=cnt;j++)
                {
                        scanf("%d",&tmp);
                        if (!tmp) t1++;
                        else
                        {
                                if (v[tmp]) mini[i]++; else t2++;
                        }
                }
                maxi[i]=mini[i]+min(t1,(m-mini[i]));
                mini[i]+=max(t1-(n-m-t2),0);
        }
        for (i=1;i<=num;i++)
        {
                tmin=10000000; tmax=-10000000; flag=0;
                for (j=1;j<=num;j++)
                {
                        if (j==i) continue;
                        if (mini[j]>maxi[i])
                        {
                                printf("1\n"); flag=1; break;
                        }
                        if (mini[j]<tmin) tmin=mini[j];
                        if (maxi[j]>tmax) tmax=maxi[j];
                }

                if (!flag) if (mini[i]>=tmax) printf("0\n"); else printf("2\n");
        }
        return 0;
}