#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n,t,a[505],Delta;
map<int,int> mp;
vector<pair<int,int> > Ans1; 
vector<int> Ans2;

void Solve()
{
//    for(int i=1;i<=n;i++) printf("-- %d\n",a[i]);
//    printf("\n");
    int NowPos=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[1])
        {
            NowPos=i;
            break;
        }
    }
    for(int j=2;j<NowPos;j++)
    {
        Ans1.push_back(make_pair(Delta+NowPos+j-2,a[j]));
    }
    Ans2.push_back(2*(NowPos-1));
    Delta+=2*(NowPos-1);
    reverse(a+1,a+NowPos+1);
    for(int i=2;i<=n;i++)
    {
        if(i<NowPos) a[i-1]=a[i];
        if(i>NowPos) a[i-2]=a[i];
    }
    n-=2;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        Ans1.clear();
        Ans2.clear();
        mp.clear();
        Delta=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }
        bool flag=false;
        for(auto &p : mp)
        {
            if(p.second%2==1) flag=true;
        }
        if(flag)
        {
            printf("-1\n");
            continue;
        }
        int tmpn=n;
        for(int i=1;i<=tmpn/2;i++) Solve();
        printf("%d\n",Ans1.size());
        for(auto &p : Ans1)
        {
            printf("%d %d\n",p.first,p.second);
        }
        printf("%d\n",Ans2.size());
        for(auto &p : Ans2)
        {
            printf("%d ",p);
        }
        printf("\n");
    }
}