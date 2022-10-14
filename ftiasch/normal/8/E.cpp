// Codeforces Beta Round #8
// Problem E -- Beads
#include <iostream>

#define maxN 50

using namespace std;

int n, a[maxN];
long long k;

long long count(int *a)
{
    int l = 0;
    for(int i = 0; i != n; ++ i)
        l += (a[i] != -1);
    long long ret = 0;
    if(l == n)    
    {
        ret = 1;
        if(a[n - 1] == 0)
            for(int i = 0; i != n; ++ i)
                if(a[i] != a[n - 1 - i])
                {
                    ret = a[i] < a[n - 1 - i];
                    break;
                }
        else
            for(int i = 0; i != n; ++ i)
                if(a[i] != 1 - a[n - 1 - i])
                {
                    ret = a[i] < 1 - a[n - 1 - i];
                    break;
                }
    }
    else
    {
        a[n - 1] ++;
        for(int i = 0; i != n + 1; ++ i)
            if(i == n || ((a[i] == 0 || a[i] == -1) && (a[n - 1 - i] == 1 || a[n - 1 - i] == -1) && i != n - 1 - i))
            {
                if(l <= i && i <= n - 2)
                    a[i] = 0;
                if(l <= n - i - 1 && n - i - 1 <= n - 2)
                    a[n - 1 - i] = 1;
                long long tmp = 1;
                for(int j = 0; j != n; ++ j)
                    if(a[j] == -1)
                        tmp *= 2;
                for(int j = 0; j != i; ++ j)
                {
                    if(a[j] != -1 && a[n - 1 - j] != -1 && a[j] != a[n - 1 - j])
                        tmp = 0;
                    if((a[j] == -1 || a[n - 1 - j] == -1) && j < n - 1 - j)
                        tmp /= 2;
                }
                ret += tmp;
                if(l <= i && i <= n - 2)
                    a[i] = -1;
                if(l <= n - i - 1 && n - i - 1 <= n - 2)
                    a[n - 1 - i] = -1;
            }
        a[n - 1] ++;
        for(int i = 0; i != n + 1; ++ i)
            if(i == n || ((a[i] == 0 || a[i] == -1) && (a[n - 1 - i] == 0 || a[n - 1 - i] == -1)))
            {
                if(l <= i && i <= n - 2)
                    a[i] = 0;
                if(l <= n - i - 1 && n - i - 1 <= n - 2)
                    a[n - 1 - i] = 0;
                long long tmp = 1;
                for(int j = 0; j != n; ++ j)
                    if(a[j] == -1)
                        tmp *= 2;                
                for(int j = 0; j != i; ++ j)
                {
                    if(a[j] != -1 && a[n - 1 - j] != -1 && a[j] != 1 - a[n - 1 - j])
                        tmp = 0;                    
                    if((a[j] == -1 || a[n - 1 - j] == -1) && j < n - 1 - j)
                        tmp /= 2;
                    if(j == n - 1 - j)
                        tmp = 0;
                }                
                ret += tmp;
                if(l <= i && i <= n - 2)
                    a[i] = -1;
                if(l <= n - i - 1 && n - i - 1 <= n - 2)
                    a[n - 1 - i] = -1;
            }        
        a[n - 1] = -1;
    }
    for(int i = 0; i != n; ++ i)
        if(a[i] == 1)
            return ret;
    return ret - 1;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i != n; ++ i)
        a[i] = -1;
    a[0] ++;
    for(int i = 1; i != n; ++ i)
    {
        a[i] ++;
        long long temp = count(a);
        if(temp < k)
            k -= temp, a[i] ++;
        if(count(a) < k)
        {
            cout << "-1\n";
            return 0;        
        }
    }
    for(int i = 0; i != n; ++ i)
        cout << a[i];
    cout << "\n";
    return 0;
}