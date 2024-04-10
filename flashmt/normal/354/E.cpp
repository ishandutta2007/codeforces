#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

vector <int> b;
int id[33], cnt4[33], cnt7[33];
long long p10[20], mx[20];

int att(long long n, int i)
{
    if (i == 0)
    {
        for (int j = 0; j < int(b.size()); j++)
            if (b[j] == n)
            {
                id[0] = j;
                return 1;
            }
        return 0;
    }
    
    for (int j = 0; j < int(b.size()); j++)
    {
        long long nn = n - p10[i] * b[j];
        if (nn < 0) continue;
        if (nn > mx[i - 1]) continue;
        id[i] = j;
        if (att(nn, i - 1)) return 1;
    }
    
    return 0;
}

void solve(long long n)
{
    memset(id, 0, sizeof id);
    
    int found = 0;
    for (int i = 0; i <= 17; i++) 
        if (mx[i] >= n)
            if (att(n, i))
            {
                found = 1;
                break;
            }
        
    if (!found) 
    {
        puts("-1");
        return;
    }
        
    long long ans[6] = {0};
    for (int i = 0; i <= 17; i++)
    {
        for (int j = 0; j < cnt4[id[i]]; j++) ans[j] += p10[i] * 4;
        for (int j = cnt4[id[i]]; j < cnt4[id[i]] + cnt7[id[i]]; j++) ans[j] += p10[i] * 7;
    }
    long long sum = 0;
    for (int i = 0; i < 6; i++) cout << ans[i] << (i == 5 ? '\n' : ' ');
}

int main()
{
    for (int i = 0; i <= 17; i++) p10[i] = i ? p10[i - 1] * 10 : 1;
    for (int i = 0; i <= 17; i++) mx[i] = mx[i - 1] + p10[i] * 42;
    
    for (int i = 0; i <= 6; i++)
        for (int j = 0; j + i <= 6; j++)
        {
            b.push_back(i * 7 + j * 4);
            cnt4[b.size() - 1] = j;
            cnt7[b.size() - 1] = i;
        }
        
    int test;
    long long n;
    cin >> test;
    while (test--)
    {
        cin >> n;
        solve(n);
    }
}