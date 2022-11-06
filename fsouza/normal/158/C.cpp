#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char cmd[10], cd[256];

int main()
{
    int n;
    vector <char> path;
    path.push_back('/');

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %s", cmd);
        if (!strcmp(cmd, "pwd")) {
            for (int i = 0; i < path.size(); i++)
                printf("%c", path[i]);
            printf("\n");
        } else {
            scanf(" %s", cd);
            int i = 0;
            if (cd[i] == '/') {
                path.clear();
                path.push_back('/');
                i++;
            }
            
            while (cd[i]) {
                if (cd[i] == '.') {
                    do {
                        path.pop_back();
                    } while (path.back() != '/');
                    i += 2;
                    if (cd[i] == '/')
                        i++;
                } else {
                    path.push_back(cd[i]);
                    i++;
                }
            }
            if (path.back() != '/') path.push_back('/');
        }
    }

    return 0;
}