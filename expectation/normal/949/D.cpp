#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

const LL mod = 1000000007;

int n,d,b;
int a[200000];
int A[200000];

bool ok(int num)
{
    FOR (i,0,n) A[i] = a[i];
    LL f1 = num, f2 = n-num-1, s1 = 0, s2 = n-1;
    while (f1 < f2)
    {
        int val, N;
        N = b;
        while (N && s1-f1 <= 1LL*d*(f1+1)) {val = min(A[s1],N), N-= val, A[s1] -= val; if (A[s1] == 0) s1++;}
        if (N) return false;
        N = b;
        while (N && f2-s2 <= 1LL*d*(f1+1)) {val = min(A[s2],N), N-= val, A[s2] -= val; if (A[s2] == 0) s2--;}
        if (N) return false;
        f1++; f2--;
    }
    return true;
}

int main()
{
    scanf("%d%d%d",&n,&d,&b);
    //n = 4; d = 3; b = 1; a[0] = n*b;
    FOR (i,0,n) scanf("%d",a+i);
    int l = 0, r = (n+1)/2;
    while (l != r)
    {
        int x = (l+r)/2;
        if (ok(x)) r = x;
        else l = x+1;
    }
    cout << l;
}