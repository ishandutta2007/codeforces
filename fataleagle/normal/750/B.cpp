#include <bits/stdc++.h>

using namespace std;

int N;
char buf[1000];

int main()
{
    scanf("%d", &N);
    int p=0;
    for(int i=0; i<N; i++)
    {
        int t;
        scanf("%d%s", &t, buf);
        if(buf[0]=='N')
        {
            if(p-t<0)
                return printf("NO\n"), 0;
            p-=t;
        }
        else if(buf[0]=='S')
        {
            if(p+t>20000)
                return printf("NO\n"), 0;
            p+=t;
        }
        else if(p==0 || p==20000)
            return printf("NO\n"), 0;
    }
    if(p==0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}