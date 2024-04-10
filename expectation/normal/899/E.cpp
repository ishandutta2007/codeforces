#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

int n;
set<pair<int,pair<int,int>>> f1;
set<pair<int,pair<int,int>>> f2;
int a;
int pre;
int len;

int main()
{
    cin >> n;
    cin >> a; pre = a; len = 1;
    FOR (i,1,n)
    {
        cin >> a;
        if (a == pre) len++;
        else
        {
            f1.insert(make_pair(-len,make_pair(i,pre)));
            f2.insert(make_pair(i,make_pair(-len,pre)));
            len = 1;
            pre = a;
        }
    }
    f1.insert(make_pair(-len,make_pair(n,pre)));
    f2.insert(make_pair(n,make_pair(-len,pre)));
    int ans = 0;
    while (f1.size())
    {
        pair<int,pair<int,int>> q = *(f1.begin());
        ans++;
        f1.erase(f1.begin());
        set<pair<int,pair<int,int>>>::iterator it = f2.find(make_pair(q.second.first,make_pair(q.first,q.second.second)));
        set<pair<int,pair<int,int>>>::iterator it2 = it; it2++;
        if (it != f2.begin() && it2 != f2.end())
        {
            set<pair<int,pair<int,int>>>::iterator it3 = it; it3--;
            if (it3->second.second == it2->second.second)
            {
                f1.erase(make_pair(it3->second.first,make_pair(it3->first,it3->second.second)));
                f1.erase(make_pair(it2->second.first,make_pair(it2->first,it2->second.second)));
                pair<int,pair<int,int>> qwe = make_pair(it3->first,make_pair(it3->second.first+it2->second.first,it2->second.second));
                f2.erase(it);
                f2.erase(it2);
                f2.erase(it3);
                f2.insert(qwe);
                f1.insert(make_pair(qwe.second.first,make_pair(qwe.first,qwe.second.second)));
            }
            else f2.erase(it);
        }
        else
            f2.erase(it);
    }
    cout << ans;
}