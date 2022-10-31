#include <bits/stdc++.h>

using namespace std;

vector<string> inputs;

int main()
{
    int mxl = 0;
    string str;
    while(getline(cin, str))
    {
        mxl = max(mxl, (int) str.size());
        inputs.push_back(str);
    }
    for(int i = 0; i < mxl+2; i++) cout << '*';
    cout << '\n';
    int now = 0;
    for(auto s:inputs)
    {
        cout << '*';
        int d = mxl - s.size();
        if(!now) for(int i = 0; i < d/2; i++) cout << ' ';
        else for(int i = d/2; i < d; i++) cout << ' ';
        cout << s;
        if(!now) for(int i = d/2; i < d; i++) cout << ' ';
        else for(int i = 0; i < d/2; i++) cout << ' ';
        if(d&1) now^=1;
        cout << '*';
        cout << '\n';
    }
    for(int i = 0; i < mxl+2; i++) cout << '*';
    cout << '\n';
}