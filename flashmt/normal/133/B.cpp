#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const string s="><+-.,[]";

int main()
{
    string a;
    int ans=0,p=1;
    cin >> a;
    for (int i=a.size()-1;i>=0;i--)
    {
        int x;
        for (x=0;x<8 && s[x]!=a[i];x++);
        ans+=(8+x)*p;
        ans%=1000003;
        p=p*16%1000003;
    }
    cout << ans << endl;
}