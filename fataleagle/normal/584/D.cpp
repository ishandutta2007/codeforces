#include <bits/stdc++.h>

using namespace std;

int N;

bool prime(int x)
{
    if(x<2)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int i=3; 1LL*i*i<=x; i+=2) if(x%i==0)
        return false;
    return true;
}

pair<int, int> goldbach(int x)
{
    if(x==0)
        return make_pair(0, 0);
    if(x==2)
        return make_pair(2, 0);
    for(int i=2; i<x; i++)
        if(prime(i) && prime(x-i))
            return make_pair(i, x-i);
    __builtin_unreachable();
}

int main()
{
    scanf("%d", &N);
    for(int i=N; i>=3; i--) if(prime(i))
    {
        vector<int> ans;
        ans.push_back(i);
        auto r=goldbach(N-i);
        if(r.first)
            ans.push_back(r.first);
        if(r.second)
            ans.push_back(r.second);
        printf("%d\n", ans.size());
        for(int i=0; i<(int)ans.size(); i++)
            printf("%d ", ans[i]);
        printf("\n");
        break;
    }
    return 0;
}