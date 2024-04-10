#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    if (n%2==0||m%2==0) cout << (n*m)/2 << endl;
    else cout << (n*m-1)/2 << endl;
    return 0;
}