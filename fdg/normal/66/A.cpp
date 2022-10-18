#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    string s;
    cin >> s;
    string b1="-128",b2="127";
    string s1="-32768",s2="32767";
    string i1="-2147483648",i2="2147483647";
    string l1="-9223372036854775808",l2="9223372036854775807";
    if (s[0]=='-')
    {
        if (s<=b1&&s.size()==b1.size()||s.size()<b1.size()) cout << "byte\n";
        else if (s<=s1&&s.size()==s1.size()||s.size()<s1.size()) cout << "short\n";
        else if (s<=i1&&s.size()==i1.size()||s.size()<i1.size()) cout << "int\n";
        else if (s<=l1&&s.size()==l1.size()||s.size()<l1.size()) cout << "long\n";
        else cout << "BigInteger\n";
    }
    else
    {
        if (s<=b2&&s.size()==b2.size()||s.size()<b2.size()) cout << "byte\n";
        else if (s<=s2&&s.size()==s2.size()||s.size()<s2.size()) cout << "short\n";
        else if (s<=i2&&s.size()==i2.size()||s.size()<i2.size()) cout << "int\n";
        else if (s<=l2&&s.size()==l2.size()||s.size()<l2.size()) cout << "long\n";
        else cout << "BigInteger\n";
    }
    return 0;
}