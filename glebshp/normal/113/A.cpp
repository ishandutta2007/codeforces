#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 1000 * 1000;

vector <pair <int, int> > words;
char buf[size];

bool increasing()
{
    int i;
    for (i = 0; i < words.size() - 1; i++)
        if (words[i].fs > words[i + 1].fs)
            return false;
    return true;
}

bool exactlyone()
{
    int i, cnt = 0;
    for (i = 0; i < words.size(); i++)
        cnt += (words[i].fs == 1);
    return (cnt == 1);
}

bool allmen()
{
    int i;
    for (i = 0; i < words.size(); i++)
        if (words[i].sc == 1)
            return false;
    return true;
}

bool allwomen()
{
    int i;
    for (i = 0; i < words.size(); i++)
        if (words[i].sc == 0)
            return false;
    return true;
}

bool inpetr(int len)
{
    int i;
   // cerr << len << endl;
    for (i = 0; i < len / 2; i++)
        swap(buf[i], buf[len - i - 1]);
    if (len >= 4 && buf[0] == 's' &&  buf[1] == 'o' && buf[2] == 'i' && buf[3] == 'l')
        return true;
    if (len >= 5 && buf[0] == 'a' && buf[1] == 'l' && buf[2] == 'a' && buf[3] == 'i' && buf[4] == 'l')
        return true;
    if (len >= 3 && buf[0] == 'r' && buf[1] == 't' && buf[2] == 'e')
        return true;
    if (len >= 4 && buf[0] == 'a' && buf[1] == 'r' && buf[2] == 't' && buf[3] == 'e')
        return true;
    if (len >= 6 && buf[0] == 's' && buf[1] == 'i' && buf[2] == 't' && buf[3] == 'i' && buf[4] == 'n' && buf[5] == 'i')
        return true;
    if (len >= 6 && buf[0] == 's' && buf[1] == 'e' && buf[2] == 't' && buf[3] == 'i' && buf[4] == 'n' && buf[5] == 'i')
        return true;
   // cerr << "badword" << endl;
    return false;
}

int main()
{
    int i, len;

   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);

    while (true)
    {
        buf[0] = '\0';
        scanf("%s", buf);
        len = strlen(buf);
        while (len > 0 && (buf[len - 1] < 'a' || buf[len - 1] > 'z'))
            len--;
        if (len == 0)
            break;

        switch(buf[len - 2])
        {
            case 'o':
            {
                words.pb(mp(0, 0));
                break;
            }
            case 'l':
            {
                words.pb(mp(0, 1));
                break;
            }
            case 't':
            {
                words.pb(mp(1, 0));
                break;
            }
            case 'r':
            {
                words.pb(mp(1, 1));
                break;
            }
            case 'i':
            {
                words.pb(mp(2, 0));
                break;
            }
            case 'e':
            {
                words.pb(mp(2, 1));
                break;
            }
        };
        if (!inpetr(len))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (words.size() == 1)
    {
        cout << "YES" << endl;
        return 0;
    }
    if (increasing() && exactlyone() && (allmen() || allwomen()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}