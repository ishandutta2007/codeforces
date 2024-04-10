    #include<cstdio>
    #include<cmath>
    #include<algorithm>
    using namespace std;
    int n,a[200005];
    pair<int,int> p[5000005];
    int main()
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        if(n>3000) n=3000;
        int tx=0,ty=0,tz=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[i]==a[j])
                {
                    if(tx!=0 && tx!=j && ty!=j)
                    {
                        printf("YES\n%d %d %d %d\n",tx,i,ty,j);
                        return 0;
                    }
                    else if(tx!=0 && (tx==j || ty==j))
                    {
                        tz=i;
                    }
                    else
                    {
                        tx=i; ty=j;
                    }
                }
            }
        }
        for(int i=1;i<=5000000;i++) p[i]=make_pair(0,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i==tz || j==tz) continue;
                if((i==ty || j==ty) && i!=tx && j!=tx) continue;
                if(p[a[i]+a[j]].first!=0) 
                {
                    printf("YES\n%d %d %d %d\n",p[a[i]+a[j]].first,p[a[i]+a[j]].second,i,j);
                    return 0;
                }
                p[a[i]+a[j]]=make_pair(i,j);
            }
        }
        printf("NO\n");
    }