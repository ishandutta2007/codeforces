#include <iostream>
#include <fstream>
using namespace std;

string s1,s2;
int a1,a2,n,i;

int main()
{
    cin >> s1 >> s2;
    for (; s1[i] != '|'; ++i) ++a1;
    for (++i; s1[i]; ++i) ++a2;
    n = s2.length();

    if (a1 + a2 + n & 1) {cout<<"Impossible"; return 0; }
    if (a2 + n < a1) {cout<<"Impossible"; return 0; }
    if (a1 + n < a2) {cout<<"Impossible"; return 0; }
    while (n) {
        string qqq = " ";
        qqq[0] = s2[0];
        if (a1 > a2) {
            s1.insert(s1.length(),qqq);
            ++a2;
        } else {
            s1.insert(0,qqq);
            ++a1;
        }
        s2.erase(0,1);
        --n;
    }
    cout << s1;

    return 0;
}