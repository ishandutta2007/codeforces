#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPN(i, a, b) for(int i = a; i >= b; i--)

string s;

int k;

bool besk = 0;
int mini, maxi;

int main()
{
    cin >> s >> k;
    mini = s.size();
    maxi = s.size();
    REP(i, 0, s.size())
    {
        if(s[i] == '?')
        {
            mini -= 2;
            maxi -= 1;
        }
        else if(s[i] == '*')
        {
            mini -= 2;
            maxi -= 1;
            besk = 1;
        }
    }
    if(mini > k)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    if(!besk && maxi < k)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    int raz = k - mini;
    REP(i, 0, s.size())
    {
        if(s[i] == '?' || s[i] == '*')
        {
            continue;
        }
        if(i == s.size() - 1)
        {
            cout << s[i];
            continue;
        }
        if(s[i + 1] == '?')
        {
            if(raz)
            {
                raz--;
                cout << s[i];
                continue;
            }
            else
            {
                continue;
            }
        }
        if(s[i + 1] == '*')
        {
            if(raz)
            {
                REP(j, 0, raz)
                {
                    cout << s[i];
                }
                raz = 0;
                continue;
            }
            else
            {
                continue;
            }
        }
        cout << s[i];
    }
    return 0;
}