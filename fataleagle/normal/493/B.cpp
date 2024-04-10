#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, B;

int main()
{
    scanf("%d", &N);
    int a, last=0;
    long long x=0, y=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        if(a>0)
            A.push_back(a), x+=a, last=0;
        else
            B.push_back(-a), y-=a, last=1;
    }
    if(x>y)
        puts("first");
    else if(x<y)
        puts("second");
    else if(A>B)
        puts("first");
    else if(B>A)
        puts("second");
    else if(last)
        puts("second");
    else
        puts("first");
    return 0;
}