#include <bits/stdc++.h>

using namespace std;

int N, T;
vector<int> A[101];

int main()
{
    scanf("%d%d", &N, &T);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        A[a].push_back(b);
    }
    for(int i=1; i<T; i++)
    {
        sort(A[i].begin(), A[i].end());
        while(A[i].size()>=2)
        {
            int tmp=A[i].back();
            A[i].pop_back();
            tmp+=A[i].back();
            A[i].pop_back();
            A[i+1].push_back(tmp);
        }
        while(!A[i].empty())
        {
            A[i+1].push_back(A[i].back());
            A[i].pop_back();
        }
    }
    sort(A[T].begin(), A[T].end());
    printf("%d\n", A[T].back());
    return 0;
}