#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <set>

using namespace std;

struct Time
{
    long long plu,sub;
    bool operator < (const Time &p) const
    {
        if (plu != p.plu) return plu < p.plu;
        return sub < p.sub;
    }
    Time() {}
    Time(long long _plu,long long _sub) : plu(-_plu),sub(-_sub) {}
    Time(long long v,long long t,long long x)
    {
        plu = -v*t-x;
        sub = -v*t+x;
    }
};

const int maxn = 1000007;

int n,v;
set<Time> idx[maxn];
pair<int,int> inc[maxn];

int fuck1()
{
    int total = 0;
    for (int i = 0;i < n;++i) idx[i].clear();
    idx[0].insert(Time(0,0));
    int ret = 0;
    for (int i = 0;i < n;++i)
    {
        Time it(v,inc[i].first,inc[i].second);
        int l = 0,r = total;
        while (l < r)
        {
            int mid = ((l+r)>>1)+1;
            set<Time>::iterator itx = idx[mid].lower_bound(it);
            if (itx != idx[mid].end() && itx->plu >= it.plu && itx->sub >= it.sub)
                l = mid;
            else
                r = mid-1;
        }
        set<Time>::iterator itx = idx[l].lower_bound(it);
        if (itx != idx[l].end() && itx->plu >= it.plu && itx->sub >= it.sub)
        {
            ret = max(ret,l+1);
            idx[l+1].insert(it);
            while (true)
            {
                set<Time>::iterator itx = idx[l+1].find(it);
                if (itx==idx[l+1].begin()) break;
                --itx;
                if (itx -> plu <= it.plu && itx->sub <= it.sub)
                    idx[l+1].erase(itx);
                else break;
            }
            if (l == total) ++total;
        }
    }
    return ret;
}

int fuck2()
{
    int total = 0;
    for (int i = 0;i < n;++i) idx[i].clear();
    idx[0].insert(Time(-0x7f7f7f7f7f7fll,-0x7f7f7f7f7f7fll));
    int ret = 0;
    for (int i = 0;i < n;++i)
    {
        Time it(v,inc[i].first,inc[i].second);
        int l = 0,r = total;
        while (l < r)
        {
            int mid = ((l+r)>>1)+1;
            set<Time>::iterator itx = idx[mid].lower_bound(it);
            if (itx != idx[mid].end() && itx->plu >= it.plu && itx->sub >= it.sub)
                l = mid;
            else
                r = mid-1;
        }
        set<Time>::iterator itx = idx[l].lower_bound(it);
        if (itx != idx[l].end() && itx->plu >= it.plu && itx->sub >= it.sub)
        {
            ret = max(ret,l+1);
            idx[l+1].insert(it);
            while (true)
            {
                set<Time>::iterator itx = idx[l+1].find(it);
                if (itx==idx[l+1].begin()) break;
                --itx;
                if (itx -> plu <= it.plu && itx->sub <= it.sub)
                    idx[l+1].erase(itx);
                else break;
            }
            if (l == total) ++total;
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0;i < n;++i) cin >> inc[i].second >> inc[i].first;
    cin >> v;
    sort(inc,inc+n);
    cout << fuck1() << " " << fuck2() << endl;
    return 0;
}