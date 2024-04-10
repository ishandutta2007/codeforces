#include <bits/stdc++.h>

using namespace std;

int pr[4]={2, 3, 5, 7};

bool divs(int x)
{
    printf("%d\n", x);
    fflush(stdout);
    char response[100];
    scanf("%s", response);
    return response[0]=='y';
}

int main()
{
    int p=-1, c=0;
    for(int i=0; i<4; i++)
    {
        if(divs(pr[i]))
        {
            p=i;
            c++;
        }
    }
    if(c==0)
        printf("prime\n");
    else if(c>1)
        printf("composite\n");
    else
    {
        vector<int> test;
        for(int i=2; i<=100; i++) if(i%pr[p]==0 && i!=pr[p])
        {
            bool none=true;
            for(int j=0; j<4; j++) if(j!=p)
                none&=i%pr[j]!=0;
            for(auto& it: test)
                none&=i%it!=0;
            if(none)
            {
                if(divs(i))
                    return printf("composite\n"), 0;
                test.push_back(i);
            }
        }
        printf("prime\n");
    }
    return 0;
}