#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define ll long long

int main()
{
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    ll n,m,v,k=-1;
    cin >> n >> m >> v;
    vector <int> v1,v2;
    for(ll i=1;i<n-1;i++)
    {
        if (i*(i+1)/2+(n-i)*(n-i-1)/2>=m)
        {
            k=i;
            break;
        }
    }
    if (n>m+1||k==-1)
    {
        cout << -1 << endl;
        return 0;
    }
    int h=1;
    for(int i=1;i<=n;i++)
    {
        if (v1.size()==k) break;
        if (i==v) continue;
        v1.push_back(i);
        h=i;
    }
    for(int j=h+1;j<=n;j++)
    {
        if (j==v) continue;
        v2.push_back(j);
    }
    /*for(int i=0;i<v1.size();i++)
        cout << v1[i] << "  ";
    cout << endl;
    for(int i=0;i<v2.size();i++)
        cout << v2[i] << "  ";*/
    int num=0;
    for(int i=1;i<v1.size();i++)
    {
        cout << v1[i-1] << " " << v1[i] << endl;
        num++;
    }
    cout << v1[v1.size()-1] << " " << v << endl;
    cout << v2[0] << " " << v << endl;
    num+=2;
    for(int i=1;i<v2.size();i++)
    {
        cout << v2[i-1] << " " << v2[i] << endl;
        num++;
    }
    if (num==m) return 0;
    for(int i=1;i<v2.size();i++)
    {
        cout << v << " " << v2[i] << endl;
        num++;
        if (num==m) return 0;
    }
    for(int i=0;i<v1.size()-1;i++)
    {
        cout << v1[i] << " " << v << endl;
        num++;
        if (num==m) return 0;
    }
    for(int i=0;i<v2.size();i++)
        for(int j=i+2;j<v2.size();j++)
        {
            cout << v2[i] << " " << v2[j] << endl;
            num++;
            if (num==m) return 0;
        }
    for(int i=0;i<v1.size();i++)
        for(int j=i+2;j<v1.size();j++)
        {
            cout << v1[i] << " " << v1[j] << endl;
            num++;
            if (num==m) return 0;
        }
    return 0;
}