#include <bits/stdc++.h>

using namespace std;

string a, b, c, d;

int main()
{
    cin>>a>>b>>c>>d;
    reverse(b.begin(), b.end());
    reverse(d.begin(), d.end());
    a+=b;
    c+=d;
    a.erase(a.find('X'), 1);
    c.erase(c.find('X'), 1);
    while(a[0]!='A')
        rotate(a.begin(), a.begin()+1, a.end());
    while(c[0]!='A')
        rotate(c.begin(), c.begin()+1, c.end());
    if(a==c)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}