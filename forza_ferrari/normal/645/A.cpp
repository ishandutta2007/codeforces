#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int k;
char a[2][2],b[2][2];
vector<char> v[2];
int main()
{
    cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1]>>b[0][0]>>b[0][1]>>b[1][0]>>b[1][1];
    k=(a[0][0]!='X')+(a[0][1]!='X')+(a[1][0]!='X')+(a[1][1]!='X');
    if(k<=2)
    {
        puts("Yes");
        return 0;
    }
    if(k==4)
    {
        if(a[0][0]==b[0][0]&&a[0][1]==b[0][1]&&a[1][0]==b[1][0]&&a[1][1]==b[1][1])
            puts("Yes");
        else
            puts("No");
        return 0;
    }
    if(a[0][0]!='X')
        v[0].push_back(a[0][0]);
    if(a[0][1]!='X')
        v[0].push_back(a[0][1]);
    if(a[1][1]!='X')
        v[0].push_back(a[1][1]);
    if(a[1][0]!='X')
        v[0].push_back(a[1][0]);
    if(b[0][0]!='X')
        v[1].push_back(b[0][0]);
    if(b[0][1]!='X')
        v[1].push_back(b[0][1]);
    if(b[1][1]!='X')
        v[1].push_back(b[1][1]);
    if(b[1][0]!='X')
        v[1].push_back(b[1][0]);
    for(register int i=1;i<=3;++i)
    {
        v[1].push_back(v[1][0]);
        v[1].erase(v[1].begin());
        if(v[0]==v[1])
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}