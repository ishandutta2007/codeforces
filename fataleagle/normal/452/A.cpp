#include <bits/stdc++.h>

using namespace std;

string names[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool check(string a, string b)
{
    if(a.length()!=b.length())
        return false;
    for(int i=0; i<a.length(); i++)
        if(b[i]!='.' && a[i]!=b[i])
            return false;
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    getline(cin, s);
    for(auto name: names)
        if(check(name, s))
        {
            cout<<name<<endl;
            break;
        }
    return 0;
}