#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, rj = 0;
int jed [maxn];
int dva [maxn];
int zajnap [maxn] [maxn];
int zajnaz [maxn] [maxn];
int br [maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &br [i]);
    }
    jed [0] = br [0] == 1 ? 1 : 0;
    dva [0] = br [0] == 2 ? 1 : 0;
    for (int i = 1; i < n; i++)
    {
        jed [i] = jed [i - 1] + (br [i] == 1 ? 1 : 0);
        dva [i] = dva [i - 1] + (br [i] == 2 ? 1 : 0);
    }
    for (int i = 0; i < n; i++)
    {
        zajnap [i] [i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            zajnap [i] [j] = max(i == 0 ? jed [j] : (jed [j] - jed [i - 1]), zajnap [i] [j - 1] + (br [j] == 2 ? 1 : 0));
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        zajnaz [i] [i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            zajnaz [i] [j] = max(j == 0 ? jed [i] : (jed [i] - jed [j - 1]), zajnaz [i] [j + 1] + (br [j] == 2 ? 1 : 0));
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            //cout << (i == 0 ? 0 : jed [i - 1]) + (i == 0 ? jed [j] : (jed [j] - jed [i - 1])) + zajnap [j + 1] [n - 1] << endl;
            //cout << (i == 0 ? 0 : jed [i - 1]) + zajnaz [j] [i] + dva [n - 1] - dva [j] << endl;
            //cout << (i == 0 ? 0 : zajnap [0] [i - 1]) + (i == 0 ? dva [j] : (dva [j] - dva [i - 1])) + dva [n - 1] - dva [j] << endl;
            //cout << endl;
            rj = max(rj, max(max((i == 0 ? 0 : jed [i - 1]) + (i == 0 ? jed [j] : (jed [j] - jed [i - 1])) + zajnap [j + 1] [n - 1], (i == 0 ? 0 : jed [i - 1]) + zajnaz [j] [i] + dva [n - 1] - dva [j]), (i == 0 ? 0 : zajnap [0] [i - 1]) + (i == 0 ? dva [j] : (dva [j] - dva [i - 1])) + dva [n - 1] - dva [j]));
        }
    }
    printf("%d", rj);
    return 0;
}