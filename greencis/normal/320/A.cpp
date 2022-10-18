#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    bool good = true;
    if (s[0] == '4') good = false;
    else {
        for (int i = 0; i < s.length(); ++i)
        if (s[i] != '1' && s[i] != '4') {good=false;break;}
        if (good) {
            if (s.find("444") != s.npos) good = false;
        }
    }
    cout<<(good?"YES":"NO");
    return 0;
}