#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define REP(i,n) for (int i = 0;i < n;++i)
#define FILL(x,c) memset(x,c,sizeof(x))

int a, b, c, d;
char s[3000007];

//c == d+1 b >= c a >= c
void case1()
{
    int now = 0;
    for (int i = 0;i < a-c;++i)
        s[now++] = '4';
    for (int i = 0;i < c;++i)
        s[now++] = '4',s[now++] = '7';
    for (int i = 0;i < b-c;++i)
        s[now++] = '7';
    s[now] = 0;
}

//d == c+1 a >= d b >= d
void case2()
{
    int now = 0;
    s[now++] = '7', s[now++] = '4';
    for (int i = 0;i < a-d;++i)
        s[now++] = '4';
    for (int i = 0;i < d-2;++i)
        s[now++] = '7', s[now++] = '4';
    for (int i = 0;i < b-d;++i)
        s[now++] = '7';
    s[now++] = '7', s[now++] = '4';
    s[now]= 0;
}

//c == d b >= d a >= d+1
void case3()
{
    int now = 0;
    for (int i = 0;i < a-d; ++i)
        s[now++] = '4';
    for (int i = 0;i < d-1;++i)
        s[now++] = '7', s[now++] = '4';
    for (int i = 0;i < b-d;++i)
        s[now++] = '7';
    s[now++] = '7', s[now++] = '4';
    s[now] = 0;
}

//c == d b >= d+1 a >= d
void case4()
{
    int now = 0;
    s[now++] = '7', s[now++] = '4';
    for (int i = 0;i < a-d;++i)
        s[now++] = '4';
    for (int i = 0;i < d-1;++i)
        s[now++] = '7', s[now++] = '4';
    for (int i = 0;i < b-d;++i)
        s[now++]= '7';
    s[now] = 0;
}

int main()
{
    cin >> a >> b >> c >> d;
    if (c == d+1 && b >= c && a >= c)
    {
        case1();
        cout << s << endl;
        return 0;
    }
    if (d == c+1 && a >= d && b >= d)
    {
        case2();
        cout << s << endl;
        return 0;
    }
    if (c == d && b >= d && a >= d+1)
    {
        case3();
        cout << s << endl;
        return 0;
    }
    if (c == d && b >= d+1 && a >= d)
    {
        case4();
        cout << s << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}