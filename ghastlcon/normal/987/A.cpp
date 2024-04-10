#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

set<string> s;

int main(void)
{
    int n;
    string x;
    int i;

    cin >> n;
    while(n --)
    {
        cin >> x;
        s.insert(x);
    }

    cout << 6 - s.size() << endl;
    if(!s.count("purple"))
        puts("Power");
    if(!s.count("green"))
        puts("Time");
    if(!s.count("blue"))
        puts("Space");
    if(!s.count("orange"))
        puts("Soul");
    if(!s.count("red"))
        puts("Reality");
    if(!s.count("yellow"))
        puts("Mind");

    return 0;
}