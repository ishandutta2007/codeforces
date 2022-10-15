#include <cstdio>

using namespace std;

const int maxN = 9876543;

int sieve[maxN], divCount[maxN], prefixDivCount[maxN];

void doSieve()
{
    for (int i = 1; i < maxN; i++) sieve[i] = i;
    for (int i = 2; i * i < maxN; i++)
        if (sieve[i] == i)
            for (int j = i + i; j < maxN; j += i) sieve[j] = i;
    divCount[1] = 0;
    for (int i = 2; i < maxN; i++) divCount[i] = divCount[i / sieve[i]] + 1;
    prefixDivCount[0] = 0;
    for (int i = 1; i < maxN; i++) prefixDivCount[i] = prefixDivCount[i - 1] + divCount[i];
}

int getInt()
{
    int n; scanf("%d", &n); return n;
}

int main()
{
    doSieve();
    int n = getInt();
    for (int i = 0; i < n; i++)
    {
        int a = getInt(), b = getInt();
        if (a < b) printf("0\n");
            else printf("%d\n", prefixDivCount[a] - prefixDivCount[b]);
    }

}