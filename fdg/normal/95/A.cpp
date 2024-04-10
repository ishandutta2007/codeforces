#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:1760777216")

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector <string> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    string s;
    char t;
    cin >> s >> t;
    vector <bool> in(s.size(),false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j+v[i].size()-1<s.size();j++)
        {
            bool ok=true;
            for(int e=0;e<v[i].size();e++)
                if (tolower(v[i][e])!=tolower(s[j+e])) ok=false;
            if (ok)
                for(int e=0;e<v[i].size();e++)
                    in[j+e]=true;
        }
    }
    for(int i=0;i<s.size();i++)
        if (in[i])
        {
            if (tolower(s[i])==tolower(t))
            {
                if (tolower(s[i])=='a')
                {
                    if (s[i]>='A'&&s[i]<='Z') s[i]='B';
                    else s[i]='b';
                }
                else
                {
                    if (s[i]>='A'&&s[i]<='Z') s[i]='A';
                    else s[i]='a';
                }
            }
            else
            {
                if (s[i]>='A'&&s[i]<='Z') s[i]=toupper(t);
                else s[i]=tolower(t);
            }
        }
    cout << s << endl;
    return 0;
}