#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        getline(cin, s);
        int r = s.find("miao."),
            f = s.find("lala.");
        while (s.find("lala.") != -1)
        {
            f = s.find("lala.");
            s[f] = 'j';
        }

        if ((r == 0 && f == s.length() - 5)
            || (r != 0 && f != s.length() - 5))
            cout << "OMG>.< I don't know!" << "\n";
        else if (r == 0)
            cout << "Rainbow's" << "\n";
        else
            cout << "Freda's" << "\n";
    }
    return 0;
}