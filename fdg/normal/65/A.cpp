#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    if (d==0) cout <<"Hermione\n";
    else if (c==0) cout << "Ron\n";
    else if (b==0) cout <<"Hermione\n";
    else if (a==0) cout << "Ron\n";
    else if (f==0) cout <<"Hermione\n";
    else if (e==0) cout << "Ron\n";
    else if (a*c*e>=b*d*f) cout <<"Hermione\n";
    else cout << "Ron\n";
    return 0;
}