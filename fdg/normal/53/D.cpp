#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#include <ctime>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector <int> a(n,0),b(n,0),x,y;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    for(int i=0;i<n;i++)
    {
        if (a[i]==b[i]) continue;
        for(int j=i+1;j<n;j++)
        {
            if (a[i]==b[j])
            {
                while(j>i)
                {
                    swap(b[j-1],b[j]);
                    y.push_back(j+1);
                    x.push_back(--j+1);
                }
                break;
            }
        }
    }
    cout << x.size() << endl;
    for(int i=0;i<x.size();i++)
        cout << x[i] << " " << y[i] << endl;
    return 0;
}