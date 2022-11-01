#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int ans2=0x3f3f3f3f;
    pair<int, int> ans;
    for(int a=1; a<=N; a++) if(N%a==0 && a<=N/a)
    {
        if(N/a-a<ans2)
            ans2=N/a-a, ans={a, N/a};
    }
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}