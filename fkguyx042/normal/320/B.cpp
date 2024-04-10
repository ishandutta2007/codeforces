#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 100 + 10;
int a[maxn], b[maxn], ans[maxn];
int n; 
void dfs(int k)
{
int i;
ans[k] = 1;
for (i = 1; i <= n; i++)
{if (a[k] > a[i] && a[k] < b[i] && !ans[i]) dfs(i);
 else if (b[k] > a[i] && b[k] < b[i] && !ans[i])
             dfs(i);
     }
 }
 int main()
{
    int i, t1, t2, choice, len;
    while (scanf("%d", &len) != EOF)
    {
        n = 0;
        for (i = 1; i <= len; i++)         {
       memset(ans, 0, sizeof(ans)); 
             scanf("%d", &choice);
            if (choice == 1)
             {
                 n++;
                 scanf("%d%d", &a[n], &b[n]);
             }
             else if (choice == 2)
             {
                 scanf("%d%d", &t1, &t2);
                 dfs(t1);
                 if (ans[t2])  
                     puts("YES");
                 else
                     puts("NO");
             }
         }
     }
     return 0;
 }