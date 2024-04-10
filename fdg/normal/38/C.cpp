#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define double long double

const double Pi=3.1415926535897932384626;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,l;
    cin >> n >> l;
    vector <int> v(n,0);
    for(int i=0;i<n;i++)
        cin >> v[i];
    int ans=0;
    for(int i=l;i<=100;i++)
    {
        int kol=0;
        for(int j=0;j<n;j++)
            kol+=v[j]/i;
        if (kol*i>ans) ans=kol*i;
    }
    cout << ans << endl;
    return 0;
}