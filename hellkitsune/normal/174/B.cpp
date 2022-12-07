#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    std::stringstream ss;
    bool ext = false;
    int l = 0, e;
    for (int r = 0; r < (int)s.length(); ++r)
    {
        if (!ext)
        {
            if (s[r] == '.')
            {
                if (l == r)
                {
                    cout << "NO";
                    return 0;
                }
                ext = true;
                e = r;
            }
            else
                if (r - l > 7)
                {
                    cout << "NO";
                    return 0;
                }
        }
        else
        {
            if (s[r] == '.')
            {
                if (r - e > 2)
                {
                    ss << s.substr(l, r - l - 1) << "\n";
                    l = r - 1;
                    e = r;
                }
                else
                {
                    cout << "NO";
                    return 0;
                }
            }
            else
            {
                if (r - e > 3)
                {
                    ss << s.substr(l, e + 4 - l) << "\n";
                    l = r;
                    ext = false;
                }
            }
        }
    }
    if ((!ext) || (s.length() - 1 - e > 3) || (s[s.length() - 1] == '.'))
    {
        cout << "NO";
        return 0;
    }
    ss << s.substr(l, s.length() - l) << "\n";
    cout << "YES\n" << ss.str();
    return 0;
}