#include<cstdio>
#include<vector>
using namespace std;
int n,k,x,ans;
bool vis[505];
vector<int> vec;
int Ask()
{
    for(int i=1;i<=n;i++) vis[i]=false;
    for(int i=0;i<vec.size();i++)
    {
        vis[vec[i]]=true;
    }
    int T=vec.size()/2;
    int tmp=0;
    printf("?");
    for(int i=0;i<T;i++)
    {
        printf(" %d",vec[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) printf(" %d",i);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d",&x);
    tmp^=x;
    printf("?");
    for(int i=T;i<2*T;i++)
    {
        printf(" %d",vec[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) printf(" %d",i);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d",&x);
    tmp^=x;
    return tmp;
}
int main()
{
    scanf("%d%d",&n,&k);
    if(n%2==1 && k%2==0) 
    {
        printf("-1\n");
        return 0;
    }
    if(n==k)
    {
        printf("?");
        for(int i=1;i<=n;i++) printf(" %d",i);
        printf("\n");
        fflush(stdout);
        scanf("%d",&x);
        printf("! %d\n",x);
        return 0; 
    }
    if(k*2>n)
    {
        if(n%2==k%2)
        {
            int Now=0;
            printf("?");
            for(int i=Now+1;i<=Now+k;i++)
            {
                printf(" %d",i);
            } 
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            ans^=x;
            Now+=k;
            int tmp1=(n-Now)/2;
            int tmp2=k-tmp1;
            printf("?");
            for(int i=1;i<=tmp2;i++)
            {
                printf(" %d",i);
            }
            for(int i=Now+1;i<=Now+tmp1;i++)
            {
                printf(" %d",i);
            }
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            ans^=x;
            Now+=tmp1;
            printf("?");
            for(int i=1;i<=tmp2;i++)
            {
                printf(" %d",i);
            }
            for(int i=Now+1;i<=Now+tmp1;i++)
            {
                printf(" %d",i);
            }
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            ans^=x;
            Now+=tmp1;
            printf("! %d\n",ans);
        }
        else
        {
            int Tk=2*n-2*k;
            int Now=0;
            do
            {
                vec.clear();
                for(int i=Now+1;i<=Now+Tk;i++)
                {
                    vec.push_back(i);
                } 
                ans^=Ask();
                Now+=Tk;
            }while(n-Now>Tk);
            int tmp1=(n-Now)/2;
            int tmp2=k-tmp1;
            printf("?");
            for(int i=1;i<=tmp2;i++)
            {
                printf(" %d",i);
            }
            for(int i=Now+1;i<=Now+tmp1;i++)
            {
                printf(" %d",i);
            }
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            ans^=x;
            Now+=tmp1;
            printf("?");
            for(int i=1;i<=tmp2;i++)
            {
                printf(" %d",i);
            }
            for(int i=Now+1;i<=Now+tmp1;i++)
            {
                printf(" %d",i);
            }
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            ans^=x;
            Now+=tmp1;
            printf("! %d\n",ans);
        }
    }
    else
    {
        int Now=0;
        while(n-Now>2*k || (n-Now)%2==1)
        {
            printf("?");
            for(int i=Now+1;i<=Now+k;i++)
            {
                printf(" %d",i);
            } 
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            ans^=x;
            Now+=k;
        }
        int tmp1=(n-Now)/2;
        int tmp2=k-tmp1;
        printf("?");
        for(int i=1;i<=tmp2;i++)
        {
            printf(" %d",i);
        }
        for(int i=Now+1;i<=Now+tmp1;i++)
        {
            printf(" %d",i);
        }
        printf("\n");
        fflush(stdout);
        scanf("%d",&x);
        ans^=x;
        Now+=tmp1;
        printf("?");
        for(int i=1;i<=tmp2;i++)
        {
            printf(" %d",i);
        }
        for(int i=Now+1;i<=Now+tmp1;i++)
        {
            printf(" %d",i);
        }
        printf("\n");
        fflush(stdout);
        scanf("%d",&x);
        ans^=x;
        Now+=tmp1;
        printf("! %d\n",ans);
    }
}