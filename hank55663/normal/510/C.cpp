#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
#include<string.h>
using namespace std;
main(){

    int n;
    int location[26];
    scanf("%d",&n);
    char name[100][200];
    for(int i=0;i<n;i++)
        scanf("%s",name[i]);
    char ans[27];
    for(int i=0;i<26;i++)
        ans[i]=i+'a';
        ans[26]=0;
    for(int t=0;t<n;t++)
    for(int i=0;i<n-1;i++)
    {
        int j;
        for(j=0;name[i][j]==name[i+1][j];j++);
        if(name[i+1][j]==0)
        {
                printf("Impossible\n");
                return 0;
        }
        else if(name[i][j]!=0)
        {
            for(int k=0;k<26;k++)
            {
                if(name[i+1][j]==ans[k])
                {
                    char temp=ans[k];
                    ans[k]=ans[k+1];
                    ans[k+1]=temp;
                }
                if(name[i][j]==ans[k])
                    break;
            }
        }
    }
    for(int i=0;i<26;i++)
        location[ans[i]-'a']=i;
    for(int i=0;i<n-1;i++)
    {
        int j;
        for(j=0;name[i][j]==name[i+1][j];j++);
        if(name[i][j]!=0)
        {
            if(location[name[i][j]-'a']>location[name[i+1][j]-'a'])
            {
                printf("Impossible\n");
                return 0;
            }
        }
    }
    printf("%s\n",ans);
    return 0;
}