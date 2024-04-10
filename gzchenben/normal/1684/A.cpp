#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, t;
vector<int> F(int x)
{
    vector<int> tmp;
    while (x)
    {
        tmp.push_back(x % 10);
        x /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        auto Now = F(n);
        if (Now.size() == 2)
            printf("%d\n", Now[1]);
        else
        {
            int ans = 10;
            for (auto &p : Now)
            {
                ans = min(ans, p);
            }
            printf("%d\n", ans);
        }
    }
}