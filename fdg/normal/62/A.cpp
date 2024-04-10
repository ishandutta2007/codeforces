#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <ctime>
#include <cmath>
#include <map>

#define ll unsigned long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int gl,gr,bl,br;
    cin >> gl >> gr >> bl >> br;
    if (gl-1<=br&&2*(gl+1)>=br||gr-1<=bl&&2*(gr+1)>=bl) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}