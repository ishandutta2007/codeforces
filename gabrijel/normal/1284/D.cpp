#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = a; i < b; i++)
 
const int maxn = 100100;
const int inf = 1e9 + 100;
 
int n;
 
vector <pair <pair <int, int>, int> > svia, svib;
 
bool po_prvom(pair <pair <int, int>, int> A, pair <pair <int, int>, int> B)
{
    if(A.first.first != B.first.first) return A.first.first < B.first.first;
    return A.second < B.second;
}
 
vector <pair <int, int> > query;
 
set <pair <int, int> > s;
set <pair <int, int> >::iterator it;
set <pair <int, int> >::iterator it2;
 
void dodaj(int a, int b)
{
    it = s.lower_bound(make_pair(a, -inf));
    int mini = a, maxi = b;
    /*./while(it -> first <= b && it != s.end())
    {
        maxi = max(maxi, it -> second);
        it2 = it;
        it++;
        s.erase(it2);
    }*/
    s.insert(make_pair(mini, maxi));
    return;
}
 
bool kriza(int a, int b)
{
    if(s.size() == 0) return 0;
    it = s.lower_bound(make_pair(a, -inf));
    if(it != s.begin())
    {
        it--;
        if(it -> second >= a) return 1;
        it++;
    }
    if(it == s.end()) return 0;
    if(it -> first <= b) return 1;
    return 0;
}
 
vector <pair <int, int> > origa, origb;
 
int main()
{
    cin >> n;
    int a, b, c, d;
    REP(i, 0, n)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        origa.push_back(make_pair(a, b));
        origb.push_back(make_pair(c, d));
        svia.push_back(make_pair(make_pair(a, b), i));
        svib.push_back(make_pair(make_pair(c, d), i));
    }
    if(n == 1)
    {
        cout << "YES" << endl;
        exit(0);
    }
    sort(svia.begin(), svia.end(), po_prvom);
    REP(i, 0, (int)svia.size())
    {
        int desna = svia[i].first.second;
        int lo = 0, hi = (int)svia.size(), mid;
        while(lo < hi)
        {
            mid = (lo + hi) / 2;
            if(svia[mid].first.first > desna) hi = mid;
            else lo = mid + 1;
        }
        if(lo == (int)svia.size()) continue;
        query.push_back(make_pair(n - lo, svia[i].second));
    }
    sort(query.begin(), query.end());
    int zadnji = 0;
    REP(i, 0, (int)query.size())
    {
        int trq = query[i].second;
        while(zadnji < query[i].first)
        {
            int trind = svia[n - 1 - zadnji].second;
            dodaj(svib[trind].first.first, svib[trind].first.second);
            zadnji++;
        }
        if(kriza(svib[trq].first.first, svib[trq].first.second))
        {
            printf("NO\n");
            exit(0);
        }
    }
    svia.clear();
    svib.clear();
    s.clear();
    query.clear();
    swap(origa, origb);
    REP(i, 0, n)
    {
        svia.push_back(make_pair(make_pair(origa[i].first, origa[i].second), i));
        svib.push_back(make_pair(make_pair(origb[i].first, origb[i].second), i));
    }
    sort(svia.begin(), svia.end(), po_prvom);
    REP(i, 0, (int)svia.size())
    {
        int desna = svia[i].first.second;
        int lo = 0, hi = (int)svia.size(), mid;
        while(lo < hi)
        {
            mid = (lo + hi) / 2;
            if(svia[mid].first.first > desna) hi = mid;
            else lo = mid + 1;
        }
        if(lo == (int)svia.size()) continue;
        query.push_back(make_pair(n - lo, svia[i].second));
    }
    sort(query.begin(), query.end());
    zadnji = 0;
    REP(i, 0, (int)query.size())
    {
        int trq = query[i].second;
        while(zadnji < query[i].first)
        {
            int trind = svia[n - 1 - zadnji].second;
            dodaj(svib[trind].first.first, svib[trind].first.second);
            zadnji++;
        }
        if(kriza(svib[trq].first.first, svib[trq].first.second))
        {
            printf("NO\n");
            exit(0);
        }
    }
    printf("YES\n");
    return 0;
}