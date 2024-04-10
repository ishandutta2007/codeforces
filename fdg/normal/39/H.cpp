#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            char mas[100];
            ltoa(i*j,mas,n);
            if (j!=n-1) cout << mas << " ";
            else cout << mas;
        }
        cout << endl;
    }
    return 0;
}