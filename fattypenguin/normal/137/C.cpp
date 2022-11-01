#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

pair<int,int> a[100007];
multiset<int> aa;

int main()
{
int n;
ios::sync_with_stdio(false);
cin>>n;
for (int i = 0;i < n;++i)
{
cin>>a[i].first>>a[i].second;
}
sort(a,a+n);
aa.clear();
int ok = 0;
for (int i = 0;i < n;)
{
int p = i;
do
{
if (aa.upper_bound(a[p].second) != aa.end()) ++ok;
++p;
} while (p < n && a[p].first == a[p-1].first);
for (int j = i;j < p;++j) aa.insert(a[j].second);
i = p;
}
cout << ok << endl;
return 0;
}