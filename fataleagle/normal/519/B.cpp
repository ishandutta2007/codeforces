#include <bits/stdc++.h>

using namespace std;

int N;
multiset<int> A, B;

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A.insert(a);
    }
    for(int i=1; i<N; i++)
    {
        scanf("%d", &a);
        A.erase(A.find(a));
        B.insert(a);
    }
    for(int i=2; i<N; i++)
    {
        scanf("%d", &a);
        B.erase(B.find(a));
    }
    printf("%d\n%d\n", *A.begin(), *B.begin());
    return 0;
}