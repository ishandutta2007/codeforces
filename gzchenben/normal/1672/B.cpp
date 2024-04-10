#include <cstdio>
#include <cstring>
using namespace std;
int n, t;
char s[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        int cntA = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'A')
                cntA++;
            else
                cntA--;
            if (cntA < 0)
                flag = false;
        }
        printf((flag && s[n] == 'B') ? "YES\n" : "NO\n");
    }
}