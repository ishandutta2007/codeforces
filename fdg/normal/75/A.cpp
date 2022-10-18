#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int dZero(int n)
{
    string res="";
    while(n>0)
    {
        if (n%10>0) res+=('0'+n%10);
        n/=10;
    }
    int ans=0;
    for(int i=res.size()-1;i>=0;i--)
        ans=ans*10+res[i]-'0';
    return ans;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,b;
    cin >> a >> b;
    cout << ((dZero(a)+dZero(b)==dZero(a+b)) ? "YES" : "NO") << endl;
    return 0;
}