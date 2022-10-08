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

const int strsize = 3 * 1000;
const int size = 3 * 1000 * 1000 + 100;
const unsigned long long hashbase = 1000 * 1000 * 1000 + 7;

unsigned long long substrs[size], pw[strsize], has[strsize];
char pat[strsize], st[strsize], fn[strsize];
bool couldst[strsize], couldfn[strsize];


int main()
{
    int lenpat, lenst, lenfn, i, j, ans, cnt = 0;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%s%s%s", pat, st, fn);
    lenpat = strlen(pat);
    while (lenpat > 0 && (pat[lenpat - 1] < 'a' || pat[lenpat - 1] > 'z'))
        lenpat--;
    lenst = strlen(st);
    while (lenst > 0 && (st[lenst - 1] < 'a' || st[lenst - 1] > 'z'))
        lenst--;
    lenfn = strlen(fn);
    while (lenfn > 0 && (fn[lenfn - 1] < 'a' || fn[lenfn - 1] > 'z'))
        lenfn--;
    pw[0] = 1;
    for (i = 1; i <= lenpat; i++)
        pw[i] = pw[i - 1] * hashbase;
    for (i = 0; i < lenpat - lenst + 1; i++)
    {
        couldst[i] = true;
        for (j = 0; j < lenst; j++)
            couldst[i] = couldst[i] && (pat[i + j] == st[j]);
    }
    for (i = 0; i < lenpat - lenfn + 1; i++)
    {
        couldfn[i] = true;
        for (j = 0; j < lenfn; j++)
            couldfn[i] = couldfn[i] && (pat[i + j] == fn[j]);
    }
    has[0] = (unsigned long long) pat[0];
    for (i = 1; i < lenpat; i++)
        has[i] = has[i - 1] * hashbase + (unsigned long long) pat[i];
    for (i = 0; i < lenpat; i++)
        for (j = i; j < lenpat; j++)
            if (j - i + 1 >= max(lenst, lenfn) && couldst[i] && couldfn[j - lenfn + 1])
            {
                substrs[cnt++] = has[j] - (i == 0 ? 0 : has[i - 1]) * pw[j - i + 1];
            }
    //cerr << cnt << endl;
    sort(substrs, substrs + cnt);
    i = 0;
    j = 0;
    ans = 0;
    while (i < cnt)
    {
        while (j < cnt && substrs[j] == substrs[i])
            j++;
        j--;
        ans++;
        i = ++j;
    }
    cout << ans;

    return 0;
}