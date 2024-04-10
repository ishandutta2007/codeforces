#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define ll long long

using namespace std;

map <int,string> f;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    f.clear();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int p=0,a;
        string name;
        cin >> name >> a;
        p=100*a;
        cin >> a;
        p-=50*a;
        for(int i=0;i<5;i++)
        {
            cin >> a;
            p+=a;
        }
        f.insert(make_pair(-p,name));
    }
    cout << f.begin()->second << endl;
    return 0;
}