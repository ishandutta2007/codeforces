#include <bits/stdc++.h>
using namespace std;

bool z = 1, mora, nije;
int n, m, k;
char mat [55] [55];
bool gdje [55];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", mat [i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) gdje [j] = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat [i] [j] == '#') gdje [j] = 1;
        }
        for (int ni = i + 1; ni < n; ni++)
        {
            mora = 0;
            nije = 0;
            for (int j = 0; j < m; j++)
            {
                if (gdje [j] && mat [ni] [j] != '#') nije = 1;
                else if (gdje [j] && mat [ni] [j] == '#') mora = 1;
                else if (!gdje [j] && mat [ni] [j] == '#') nije = 1;
            }
            if (nije && mora) {z = 0; break;}
        }
        if (!z) break;
    }
    if (!z) printf("No");
    else printf("Yes");
    return 0;
}