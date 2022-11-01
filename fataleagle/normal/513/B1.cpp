#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
vector<int> A, B;

int main()
{
    scanf("%d%lld", &N, &K);
    K--;
    for(int i=0; i<N-1; i++)
        if((K>>(N-i-2))&1)
            B.push_back(i+1);
        else
            A.push_back(i+1);
    for(auto& it: A)
        printf("%d ", it);
    printf("%d", N);
    reverse(B.begin(), B.end());
    for(auto& it: B)
        printf(" %d", it);
    printf("\n");
    return 0;
}