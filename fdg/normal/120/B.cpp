#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,a[1001];
    cin >> n >> k;
    k--;
    for(int i=0;i<n;i++)
        cin >> a[i];
    while(a[k]==0) k=(k+1)%n;
    cout << k+1 << endl;
    return 0;
}