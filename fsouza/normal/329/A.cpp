#include <iostream>
#include <cstdio>
#include <vector>

#define MAXN 100

using namespace std;

int M[MAXN][MAXN];

int main()
{
    int n;

    scanf("%d", &n);

    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++) {
            char c;
            scanf(" %c", &c);
            M[y][x] = (c == '.');
        }

    vector <pair <int, int> > ret;

    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            if (M[y][x]) {
                ret.push_back(make_pair(y, x));
                break;
            }

    if (ret.size() == n)
        goto done;

    ret.clear();
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            if (M[y][x]) {
                ret.push_back(make_pair(y, x));
                break;
            }
    if (ret.size() == n)
        goto done;
    
    printf("-1\n");
    return 0;

done:
    for (int i = 0; i < n; i++)
        printf("%d %d\n", ret[i].first+1, ret[i].second+1);

    return 0;
}