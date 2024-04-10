#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

#define ll long long

using namespace std;

map < pair <string,string>,int > f;


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    string mname;
    int n,p=0;
    cin >> mname >> n;
    for(int i=0;i<n;i++)
    {
        string curname,tmp,sname;
        char s;
        cin >> curname >> s;
        if (s=='p')
        {
            cin >> tmp >> tmp >> sname >> tmp;
            p=15;
        }
        if (s=='c')
        {
            cin >> tmp >> tmp >> sname >> tmp;
            p=10;
        }
        if (s=='l')
        {
            cin >> tmp >> sname >> tmp;
            p=5;
        }
        sname.erase(sname.end()-1); sname.erase(sname.end()-1);
        f[make_pair(min(sname,curname),max(sname,curname))]+=p;
        if (!f.count(make_pair(min(sname,mname),max(sname,mname)))) f[make_pair(min(sname,mname),max(sname,mname))]=0;
        if (!f.count(make_pair(min(curname,mname),max(curname,mname)))) f[make_pair(min(curname,mname),max(curname,mname))]=0;
    }
    vector < pair <int,string> > v;
    for(map < pair <string,string>,int >::iterator it=f.begin();it!=f.end();it++)
    {
        if (it->first.first==mname) v.push_back(make_pair(-it->second,it->first.second));
        if (it->first.second==mname) v.push_back(make_pair(-it->second,it->first.first));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if (v[i].second!=mname) cout << v[i].second << endl;
    }
    return 0;
}