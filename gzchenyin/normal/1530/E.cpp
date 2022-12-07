#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t;
char s[100005],Ans[100005];
int cnt[500];
bool All_Same()
{
    int flag=0;
    for(int i='a';i<='z';i++)
    {
        if(cnt[i]) flag++;
    }
    if(flag>1) return false;
    printf("%s\n",s+1);
    return true;
}
bool All_Distinct()
{
    bool flag=true;
    for(int i='a';i<='z';i++)
    {
        if(cnt[i]>1) flag=false;
    }
    if(!flag) return false;
    sort(s+1,s+n+1);
    printf("%s\n",s+1); 
    return true;
}
bool Exist_Once()
{
    char T=0;
    for(int i='a';i<='z';i++)
    {
        if(cnt[i]==1)
        {
            T=i;
            break;
        }
    }
    if(!T) return false;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==T) swap(s[1],s[i]);
    }
    sort(s+2,s+n+1);
    printf("%s\n",s+1); 
    return true;
}
bool Can_Be_Front()
{
    char Minn=0;
    for(int i='a';i<='z';i++)
    {
        if(cnt[i])
        {
            Minn=i;
            break;
        }
    }
    if(cnt[Minn]>n/2+1) return false;
    int Top=Minn+1;
    for(int i=1;i<=n;i++)
    {
        if(i>2 && (Ans[i-1]==Minn || cnt[Minn]==0)) 
        {
            while(cnt[Top]==0) Top++;
            Ans[i]=Top;
            cnt[Top]--;
        }
        else 
        {
            cnt[Minn]--;
            Ans[i]=Minn;
        }
    }
    Ans[n+1]=0;
    printf("%s\n",Ans+1);
    return true;
}
bool Exist_Others()
{
    int Tmpcnt=0;
    for(int i='a';i<='z';i++)
    {
        if(cnt[i])
        {
            Tmpcnt++;
        }
    }
    return Tmpcnt>=3;
}
void Work1()
{
    char Minn1=0,Minn2=0;
    for(int i='a';i<='z';i++)
    {
        if(cnt[i])
        {
            if(Minn1==0) Minn1=i;
            else if(Minn2==0) Minn2=i;
        }
    }
    int Top=Minn2+1;
    for(int i=1;i<=n;i++)
    {
        if(i==1) 
        {
            Ans[i]=Minn1;
            cnt[Minn1]--;
            continue;
        }
        if(i==2)
        {
            Ans[i]=Minn2;
            cnt[Minn2]--;
            continue;
        }
        if(cnt[Minn1]!=0)
        {
            Ans[i]=Minn1;
            cnt[Minn1]--;
            continue;
        }
        if(Ans[i-1]!=Minn1 && cnt[Minn2]!=0)
        {
            Ans[i]=Minn2;
            cnt[Minn2]--;
            continue;
        }
        while(cnt[Top]==0) Top++;
        Ans[i]=Top;
        cnt[Top]--;
    }
    Ans[n+1]=0;
    printf("%s\n",Ans+1);
}
void Work2()
{
    char Minn1=0,Minn2=0;
    for(int i='a';i<='z';i++)
    {
        if(cnt[i])
        {
            if(Minn1==0) Minn1=i;
            else if(Minn2==0) Minn2=i;
        }
    }
    printf("%c",Minn1);
    cnt[Minn1]--;
    while(cnt[Minn2])
    {
        printf("%c",Minn2);
        cnt[Minn2]--;
    }
    while(cnt[Minn1])
    {
        printf("%c",Minn1);
        cnt[Minn1]--;
    }
    printf("\n");
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i='a';i<='z';i++)
        {
            cnt[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cnt[s[i]]++;
        }
        if(All_Same()) continue;
        if(All_Distinct()) continue;
        if(Exist_Once()) continue;
        if(Can_Be_Front()) continue;
        if(Exist_Others()) Work1();
        else Work2();
    }
}