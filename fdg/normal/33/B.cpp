#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define ll long long

using namespace std;

char str1[100001]={0},str2[100001]={0},res[100001]={0};
int D[27][27]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    memset(str1,'\0',sizeof(str1));
    memset(str2,'\0',sizeof(str2));
    memset(res,'\0',sizeof(res));
    scanf("%s\n%s\n",str1,str2);
    for(int i=0;i<27;i++)
    {
        for(int j=0;j<27;j++)
            D[i][j]=2000;
        D[i][i]=0;
    }
    int n,c;
    scanf("%d\n",&n);
    char a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%c %c %d\n",&a,&b,&c);
        if (D[a-'a'][b-'a']==2000||D[a-'a'][b-'a']>c) D[a-'a'][b-'a']=c;
    }
    for(int k=0;k<26;k++)
    {
        for(int j=0;j<26;j++)
        {
            for(int i=0;i<26;i++)
            {
                if (i==j||j==k||k==i) continue;
                if (D[j][k]==2000||D[k][i]==2000) continue;
                if (D[j][i]>D[j][k]+D[k][i]) D[j][i]=D[j][k]+D[k][i];
            }
        }
    }
    int l=strlen(str1),ans=0;
    if (l!=strlen(str2))
    {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<l;i++)
    {
        int k=3000,ind=-1;
        for(int j=0;j<26;j++)
        {
            if ((D[str1[i]-'a'][j]+D[str2[i]-'a'][j])<k&&D[str1[i]-'a'][j]!=2000&&D[str2[i]-'a'][j]!=2000)
            {
                k=D[str1[i]-'a'][j]+D[str2[i]-'a'][j];
                ind=j;
            }
        }
        if (ind==-1)
        {
            printf("-1\n");
            return 0;
        }
        res[i]='a'+ind;
        ans+=k;
    }
    printf("%d\n%s\n",ans,res);
    return 0;
}