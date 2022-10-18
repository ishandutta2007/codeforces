#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
char s[100005];

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        s[i] = i % 4 + 'a';
    puts(s);

    return 0;
}