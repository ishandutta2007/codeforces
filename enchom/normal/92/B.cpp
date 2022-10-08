#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int bnum[1000001];
Int bL=0;

int main()
{
    string s;
    Int i;
    Int uk;
    Int moves=0;
    bool flag;
    
    cin>>s;
    
    bL=s.length();
    for (i=s.length()-1;i>=0;i--)
    {
        bnum[bL-i]=s[i]-'0';
    }
    
    uk=1;
    
    while(1)
    {
        if (bL==uk && bnum[bL]==1)
        break;
        
        moves++;
        
        if (bnum[uk]==0)
        {
            uk++;
        }
        else
        {
            bnum[uk]=0;
            flag=false;
            for (i=uk+1;i<=bL;i++)
            {
                if (bnum[i]==1)
                {
                    bnum[i]=0;
                }
                else
                {
                    flag=true;
                    bnum[i]=1;
                    break;
                }
            }
            if (!flag)
            {
                bL++;
                bnum[bL]=1;
            }
        }
    }
    printf("%I64d\n",moves);
    return 0;
}