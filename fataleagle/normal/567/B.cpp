#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> q;
vector<int> r;

int main()
{
    scanf("%d", &N);
    char c;
    int a;
    set<int> s;
    for(int i=0; i<N; i++)
    {
        scanf(" %c%d", &c, &a);
        if(c=='+')
        {
            q.push_back(a);
            s.insert(a);
        }
        else
        {
            q.push_back(-a);
            if(!s.count(a))
                r.push_back(a);
            else
                s.erase(a);
        }
    }
    int maxi=0;
    int sum=0;
    for(auto& it: r)
    {
        if(it>0)
            sum++;
        else
            sum--;
        maxi=max(maxi, sum);
    }
    for(auto& it: q)
    {
        if(it>0)
            sum++;
        else
            sum--;
        maxi=max(maxi, sum);
    }
    printf("%d\n", maxi);
    return 0;
}