#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

char str1[1000002]={0},str2[1000002]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%s\n%s\n",str1,str2);
    vector <int> ans;
    int l=strlen(str2);
    str2[l++]='A';
    for(int i=0;i<l;i++)
    {
        if (str1[i]!=str2[i])
        {
            int ind=i;
            while(ind>=0&&str1[i]==str1[ind]) ind--;
            ind++;
            for(int j=ind;j<=i;j++)
                ans.push_back(j+1);
            bool eq=true;
            for(int j=i;j<l-1;j++)
                if (str1[j+1]!=str2[j])
                {
                    eq=false;
                    break;
                }
            if (!eq) ans.clear();
            break;
        }
    }
    printf("%d\n",ans.size());
    if (ans.size()>0)
    {
        printf("%d",ans[0]);
        for(int i=1;i<ans.size();i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}