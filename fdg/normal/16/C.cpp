#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int g=gcd(x,y);
    x/=g; y/=g;
    int side=min(a/x,b/y);
    cout << side*x << " " << side*y << endl;
    return 0;
}