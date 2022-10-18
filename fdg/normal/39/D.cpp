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
    int a,b,c,A,B,C;
    cin >> a >> b >> c >> A >> B >> C;
    if (a==A||b==B||c==C)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
    return 0;
}