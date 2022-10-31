#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n, k;
int h[MAXN];
vector<int> cand;

inline bool ok(int x)
{
    static multiset<int> bst;
    bst.clear();
    cand.clear();
    for(int i = 1; i <= x-1; i++)
        bst.insert(h[i]);
    for(int i = x; i <= n; i++)
    {
        bst.insert(h[i]);
        int mn = *bst.begin();
        int mx = *bst.rbegin();
        if(mx-mn <= k) cand.push_back(i);
        bst.erase(bst.find(h[i-x+1]));
    }
    return cand.size() > 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", h+i);
    int lb = 1, ub = n, ans=1;
    while(lb <= ub)
    {
        int mid = (lb+ub)/2;
        if(ok(mid))
        {
            ans = mid;
            lb = mid+1;
        }
        else ub = mid-1;
    }
    ok(ans);
    printf("%d %d\n", ans, (int) cand.size());
    for(int &r:cand)
        printf("%d %d\n", r-ans+1, r);

}