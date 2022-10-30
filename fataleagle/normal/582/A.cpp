#include <bits/stdc++.h>

using namespace std;

int N;
multiset<int> m;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N*N; i++)
    {
        int a;
        scanf("%d", &a);
        m.insert(a);
    }
    vector<int> cur;
    for(int i=0; i<N; i++)
    {
        int x=*m.rbegin();
        printf("%d ", x);
        for(auto& it: cur)
        {
            m.erase(m.find(__gcd(it, x)));
            m.erase(m.find(__gcd(it, x)));
        }
        m.erase(m.find(x));
        cur.push_back(x);
    }
    printf("\n");
    return 0;
}