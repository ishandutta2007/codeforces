#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    map <string,int> v;
    for(int i=0;i<n;i++)
    {
        char mas[20]={0};
        cin >> mas;
        if (v.count(mas)) v[mas]++;
        else v[mas]=1;
    }
    if (v.size()==1)
    {
        cout << v.begin()->first << endl;
        return 0;
    }
    map <string,int>::iterator it=v.begin();
    map <string,int>::iterator it1=it;
    it1++;
    if ((*it).second>(*it1).second) cout << (*it).first << endl;
    else cout << (*it1).first << endl;
    return 0;
}