#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s,tmp="";
    vector<string> v;
    int curidx = 0;
    cin >> s;
    while (curidx < s.length()) {
        tmp += s[curidx++];
        if (tmp.length() > 2 && tmp[tmp.length() - 3] == 'W' &&
            tmp[tmp.length() - 2] == 'U' && tmp[tmp.length() - 1] == 'B')
        {
            tmp = tmp.substr(0,tmp.length()-3);
            v.push_back(tmp);
            tmp = "";
        }
    }
    v.push_back(tmp);

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != "")
            cout << v[i] << " ";
    }
    return 0;
}