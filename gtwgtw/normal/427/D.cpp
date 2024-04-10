#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 20005
#define limit 20000
using namespace std;


int sum[maxn],rank[maxn],tsa[maxn],sa[maxn],trank[maxn];
int h[maxn],ts;
char s[maxn];


void sorting(int x)
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=ts;i++)sum[rank[i+x]]++;
    for(int i=1;i<=limit;i++)sum[i]+=sum[i-1];
    for(int i=ts;i>=1;i--)tsa[sum[rank[i+x]]--]=i;
    
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=ts;i++)sum[rank[i]]++;
    for(int i=1;i<=limit;i++)sum[i]+=sum[i-1];
    for(int i=ts;i>=1;i--)sa[sum[rank[tsa[i]]]--]=tsa[i];
}


void Make_Suffix_Array()
{
    for(int i=1;i<=limit;i++)sum[i]+=sum[i-1];
    for(int i=ts;i>=1;i--)sa[sum[s[i]]--]=i;
    rank[sa[1]]=1;
    int p=1;
    for(int i=2;i<=ts;i++)
    {
        if(s[sa[i]]!=s[sa[i-1]])p++;
        rank[sa[i]]=p;
    }
    for(int j=1;j<=ts;j<<=1)
    {
        sorting(j);
        trank[sa[1]]=1;p=1;
        for(int i=2;i<=ts;i++)
        {
            if(rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+j]!=rank[sa[i-1]+j])p++;
            trank[sa[i]]=p;
        }
        for(int i=1;i<=ts;i++)rank[i]=trank[i];
    }
}


void Find_The_Longest_Common_Prefix()
{
    for(int i=1,j=0;i<=ts;i++)
    {
        if(rank[i]==1)continue;
        for(;s[i+j]==s[sa[rank[i]-1]+j];j++);
        h[rank[i]]=j;
        if(j)j--;
    }
    h[1]=-1;
    h[ts+1]=-1;
}


int main()
{
    char x=getchar();
    while(x>='a'&&x<='z')
    {
        s[++ts]=x;
        x=getchar();
    }
    int n1=ts;
    x=getchar();
    s[++ts]='$';
    while(x>='a'&&x<='z')
    {
        s[++ts]=x;
        x=getchar();
    }
    for(int i=1;i<=ts;i++)sum[s[i]-'\0']++;
    Make_Suffix_Array();
    Find_The_Longest_Common_Prefix();
    int ans=210000000;
    for(int i=3;i<=ts;i++)
    {
        if((sa[i]>n1&&sa[i-1]<=n1)||(sa[i]<=n1&&sa[i-1]>n1))
        {
            if(h[i]<=h[i-1]||h[i]<=h[i+1])continue;
            ans=min(ans,max(h[i-1],h[i+1])+1);
            if(ans==2)
                ans=2;
        }
    }
    if(ans==210000000)printf("-1\n");else
    printf("%d\n",ans);
    return 0;
}