// Codeforces Beta Round #10
// Problem A -- Power Consumption Calculation
#include <cstdio>

#define maxN 100

using namespace std;

int n, p_1, p_2, p_3, t_1, t_2, l[maxN], r[maxN];

int main()
{
    scanf("%d%d%d%d%d%d", &n, &p_1, &p_2, &p_3, &t_1, &t_2);
    int a = 0;
    for(int i = 0; i != n; ++ i)
    {
        scanf("%d%d", l + i, r + i);
        a += (r[i] - l[i]) * p_1;
    }
    for(int i = 1; i != n; ++ i)
    {
        int m = l[i] - r[i - 1];
        if(m >= t_1)
        {
            m -= t_1;
            if(m >= t_2)
            {
                m -= t_2;
                a += m * p_3;
                a += t_2 * p_2;            
            }
            else
                a += m * p_2;
            a += t_1 * p_1;
        }
        else
            a += m * p_1;
    }
    printf("%d\n", a);
    return 0;
}