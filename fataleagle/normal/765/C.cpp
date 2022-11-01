#include <bits/stdc++.h>

using namespace std;

int K, A, B;

int main()
{
    cin>>K>>A>>B;
    int AK=A/K;
    int BK=B/K;
    int ans=AK+BK;
    A%=K;
    B%=K;
    if(ans<1)
        return 0*printf("-1\n");
    if(B>AK*(K-1))
        return 0*printf("-1\n");
    if(A>BK*(K-1))
        return 0*printf("-1\n");
    printf("%d\n", ans);
	return 0;
}