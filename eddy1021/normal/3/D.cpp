#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int> tii;
typedef long long ll;

const int MAXN = 50010;

int n, m;
char in[MAXN];

int main()
{
    scanf("%s", in+1);
    n = strlen(in+1);
    int stk = 0;
    set<tii> heap;
    bool flag = 1;
    ll ans = 0ll;
    for(int i = 1; i <= n && flag; i++)
    if(in[i] == '?')
    {
        int lc, rc;scanf("%d%d", &lc, &rc);
        in[i] = ')';
        ans += (ll) rc;
        heap.insert(tii(lc-rc, i));
        stk--;
        if(stk < 0)
        {
            if((int)heap.size() == 0)
            {
                flag = 0;
                break ;
            }
            int dlt, pos;
            tie(dlt, pos) = *heap.begin();
            ans += (ll) dlt;
            in[pos] = '(';
            heap.erase(tii(dlt, pos));
            stk+=2;
        }
    }
    else if(in[i] == '(') stk++;
    else if(in[i] == ')')
    {
        stk--;
        if(stk < 0)
        {
            if((int)heap.size() == 0)
            {
                flag = 0;
                break ;
            }
            int dlt, pos;
            tie(dlt, pos) = *heap.begin();
            ans += (ll) dlt;
            in[pos] = '(';
            heap.erase(tii(dlt, pos));
            stk+=2;
        }
    }
    if(!flag || stk != 0) puts("-1");
    else printf("%I64d\n%s\n", ans, in+1);
}