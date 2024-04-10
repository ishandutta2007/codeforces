// Codeforces Beta Round #6
// Problem E -- Exposition
#include <cstdio>

#define maxN 100000

using namespace std;

int n, m, a[maxN], h_1, t_1, q_1[maxN], h_2, t_2, q_2[maxN], i, j, l[maxN], o, c;

int main()
{
    scanf("%d%d", &n, &m);
    h_1 = t_1 = h_2 = t_2 = o = c = 0;
    for(i = j = 0; j < n; ++ j)
    {
        scanf("%d", a + j);
        while(h_1 < t_1 && a[q_1[t_1 - 1]] >= a[j])
            t_1 --;
        while(h_2 < t_2 && a[q_2[t_2 - 1]] <= a[j])
            t_2 --;
        q_1[t_1 ++] = q_2[t_2 ++] = j;
        while(a[q_2[h_2]] - a[q_1[h_1]] > m)
        {
            i ++;
            if(q_1[h_1] < i)
                h_1 ++;
            if(q_2[h_2] < i)
                h_2 ++;
        }
        l[j] = j - i + 1;
        if(l[j] > o)
            o = l[j], c = 0;
        c += (l[j] == o);
    }
    printf("%d %d\n", o, c);
    for(i = 0; i < n; ++ i)
        if(l[i] == o)
            printf("%d %d\n", i - l[i] + 2, i + 1);
    return 0;
}