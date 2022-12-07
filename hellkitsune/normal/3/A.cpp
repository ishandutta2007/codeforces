#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void)
{
    string s1, s2, answ;
    cin >> s1 >> s2;
    cout << max(abs(s1[0] - s2[0]), abs(s1[1] - s2[1])) << endl;
    while (s1 != s2)
    {
        answ = "";
        if (s1[0] < s2[0])
        {
            answ += "R";
            ++s1[0];
        }
        if (s1[0] > s2[0])
        {
            answ += "L";
            --s1[0];
        }
        if (s1[1] < s2[1])
        {
            answ += "U";
            ++s1[1];
        }
        if (s1[1] > s2[1])
        {
            answ += "D";
            --s1[1];
        }
        cout << answ << endl;
    }
    return 0;
}