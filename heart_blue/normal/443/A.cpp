#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<char,int> m;
    char c;
    while((c = getchar())!=-1)
    {
        m[c] = 1;
    }
    m[' '] = 1;
    m[','] = 1;
    m['\n'] = 1;
    cout << m.size()-5 << endl;
    return 0;
}