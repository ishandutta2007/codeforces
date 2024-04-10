#include <bits/stdc++.h>

using namespace std;

int N, T;
int A[100000];
bool reach[100000];

int main()
{
    scanf("%d%d", &N, &T);
    reach[1]=true;
    int a;
    for(int i=1; i<N; i++)
    {
        scanf("%d", &a);
        if(reach[i])
            reach[i+a]=true;
    }
    puts(reach[T]?"YES":"NO");
    return 0;
}