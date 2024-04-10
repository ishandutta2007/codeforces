#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
char s[555555];
int n,m,a[555555],sum;
bool ol[555555],ans[555555];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)cin.ignore(),scanf("%c%d",&s[i],&a[i]);
    for(int i=0;i<m;i++)
    {
        if(s[i]=='-'&&!ol[a[i]])sum++;ol[a[i]]=1;
    }
    for(int i=0;i<m;i++)
    {
        if(s[i]=='+'){if((i&&a[i]!=a[i-1])||sum)ans[a[i]]=1;sum++;}
        else{sum--;if((i<m-1&&a[i]!=a[i+1])||sum)ans[a[i]]=1;}
    }
    sum=0;
    for(int i=1;i<=n;i++)sum+=(!ans[i]);
    printf("%d\n",sum);
    for(int i=1;i<=n;i++)if(!ans[i])printf("%d ",i);
//  system("pause");
    return 0;
}