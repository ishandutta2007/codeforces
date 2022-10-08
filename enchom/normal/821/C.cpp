#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int n;
set<int> actives;
set<int>::iterator myit;
vector<int> mystack;
int answer=0;
char inp[11];
int TOPOP=1;

void Remove()
{
    if (!mystack.empty())
    {
        if (mystack.back()==TOPOP)
        mystack.pop_back();
        else
        {
            int i;

            answer++;

            for (i=0;i<mystack.size();i++)
            {
                actives.insert(mystack[i]);
            }

            mystack.clear();

            actives.erase(TOPOP);
        }
    }
    else
    {
        actives.erase(TOPOP);
    }

    TOPOP++;

    return;
}

int main()
{
    int i;
    int val;

    scanf("%d",&n);

    for (i=1;i<=2*n;i++)
    {
        scanf("%s",inp);

        if (inp[0]=='a')
        {
            scanf("%d",&val);

            mystack.push_back(val);
        }
        else
        {
            Remove();
        }
    }

    printf("%d\n",answer);

    return 0;
}