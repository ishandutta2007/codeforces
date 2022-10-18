#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstring>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector <int> v(n,0);
    for(int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(),v.end());
//  v.push_back(10000);
    int kol=0,mx=0;
    for(int i=0;i<v.size();i++)
    {
        int j=i;
        while(j+1<v.size()&&v[j+1]==v[i]) j++;
        if (j-i+1>mx) mx=j-i+1;
        kol++;
        i=j;
    }
    cout << mx << " " << kol << endl;
    return 0;
}