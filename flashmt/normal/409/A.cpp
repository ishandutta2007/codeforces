#include <bits/stdc++.h>
using namespace std;

int score(string s1, string s2)
{
    int res = 0;
    for (int i = 0; i < int(s1.size()); i += 2)
        if (s1[i] != s2[i])
        {
            if (s1[i] == '8')
            {
                if (s2[i] == '[') res++;
                else res--;
            }
            if (s1[i] == '[')
            {
                if (s2[i] == '(') res++;
                else res--;
            }
            if (s1[i] == '(')
            {
                if (s2[i] == '8') res++;
                else res--;
            }
        }
    return res;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (!score(s1, s2)) cout << "TIE" << endl;
    else cout << "TEAM " << (score(s1, s2) > 0 ? "1" : "2") << " WINS" << endl;
}