#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>

#define ll long long

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    if ((n^(n-1))==((n<<1)-1)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}