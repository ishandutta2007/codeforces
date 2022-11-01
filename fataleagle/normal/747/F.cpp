#include <bits/stdc++.h>

using namespace std;

struct thing
{
    int a[16];
    int& operator[] (const int idx)
    {
        return a[idx];
    }
    bool operator< (const thing& other) const
    {
        for(int i=0; i<16; i++)
            if(a[i]!=other.a[i])
                return a[i]<other.a[i];
        return false;
    }
} zero;

int MAX;
int N, T;
map<thing, long long> cache[10][2];

long long rec(int pos, int leadZero, thing freq)
{
    if(pos==MAX)
        return !leadZero;
    if(cache[pos][leadZero].count(freq))
        return cache[pos][leadZero][freq];
    long long& ret=cache[pos][leadZero][freq];
    for(int i=0; i<16; i++) if(freq[i]<T)
    {
        if(!leadZero || i!=0)
            freq[i]++;
        ret+=rec(pos+1, leadZero && i==0, freq);
        if(!leadZero || i!=0)
            freq[i]--;
    }
    return ret;
}

void restore(int pos, int leadZero, thing freq, long long k)
{
    if(pos==MAX)
        return;
    for(int i=0; i<16; i++) if(freq[i]<T)
    {
        if(!leadZero || i!=0)
            freq[i]++;
        long long v=rec(pos+1, leadZero && i==0, freq);
        if(k<=v)
        {
            if(!leadZero || i!=0)
            {
                if(i<10)
                    printf("%d", i);
                else
                    printf("%c", 'a'+i-10);
            }
            restore(pos+1, leadZero && i==0, freq, k);
            return;
        }
        else
            k-=v;
        if(!leadZero || i!=0)
            freq[i]--;
    }
}

int main()
{
    MAX=9;
    scanf("%d%d", &N, &T);
    restore(0, 1, zero, N);
    printf("\n");
    return 0;
}