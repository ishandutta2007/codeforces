#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
typedef long long Int;

vector<char> stack4e;
Int n;
char a[100001];

int main()
{
    Int i;
    bool remove=false;
    char k;

    scanf("%s",a);
    n=strlen(a);

    for (i=0;i<n;i++)
    {
        k=a[i];

        if (stack4e.empty())
        {
            stack4e.push_back(k);
        }
        else
        {
            remove=false;

            while(stack4e.size()>0)
            {
                if (stack4e.back()!=k)
                break;
                else
                {
                    remove=true;
                    stack4e.pop_back();
                }
            }

            if (!remove)
            stack4e.push_back(k);
        }
    }

    if (stack4e.empty())
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}