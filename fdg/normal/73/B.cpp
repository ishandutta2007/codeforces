#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

vector < pair <string,int> > v;
vector <int> b;
string vas;

bool operator < (string a,string b)
{
    for(int i=0;i<a.size()&&i<b.size();i++)
    {
        if (a[i]<b[i]) return true;
        if (a[i]>b[i]) return false;
    }
    if (b.size()>a.size()) return true;
    return false;
}

bool sort1(pair <string,int> a,pair <string,int> b)
{
    if (a.first==vas) return true;
    if (b.first==vas) return false;
    return a.second<b.second||a.second==b.second&&a.first>b.first;
}

bool sort2(pair <string,int> a,pair <string,int> b)
{
    return a.second>b.second||a.second==b.second&&a.first<b.first;
}

multiset <int> f;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    char mas[30]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %d\n",mas,&m);
        v.push_back(make_pair(mas,m));
    }
    scanf("%d",&m);
    b.resize(m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        f.insert(b[i]);
    }
    for(int j=m;j<n;j++)
        b.push_back(0);
    sort(b.rbegin(),b.rend());
    scanf("\n%s",mas);
    vas=mas;
    sort(v.begin(),v.end(),sort1);
    int mn=1,vp=v[0].second+b[0],mx=-1;
    for(int i=1;i<n;i++)
    {
        int cp=v[i].second+b[i];
        if (cp>vp||cp==vp&&v[i].first<vas) mn++;
    }
    sort(v.begin(),v.end(),sort2);
    int ind=0;
    for(;ind<n;ind++)
        if (v[ind].first==vas) break;
    int vi=ind;
    mx=++ind;
    vp=v[vi].second;
    if (f.size()==n)
    {
        multiset <int>::iterator it=f.begin();
        vp+=(*it);
        f.erase(it);
    }
    for(;ind<n;ind++)
    {
        int val=vp-v[ind].second;
        if (v[vi].first<v[ind].first) val++;
        multiset <int>::iterator it=f.lower_bound(val);
        if (it!=f.end())
        {
            mx++;
            f.erase(it);
        }
    }
    cout << mn << " " << mx << endl;
    return 0;
}