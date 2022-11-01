#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

int n, granica;
long long int k;

vector <long long int> prosti;

vector <long long int> lijevi, desni;

bool moze(long long int a, long long int b)
{
    if(1e18 / a >= b) return 1;
    return 0;
}

void rekli(int pbroj, long long int umn, bool dodaj)
{
    if(umn > 1e18) return;
    if(dodaj) lijevi.push_back(umn);
    if(pbroj > granica) return;
    if(moze(umn, prosti[pbroj])) rekli(pbroj, umn * prosti[pbroj], 1);
    rekli(pbroj + 1, umn, 0);
    return;
}

void rekde(int pbroj, long long int umn, bool dodaj)
{
    if(umn > 1e18) return;
    if(dodaj) desni.push_back(umn);
    if(pbroj >= n) return;
    if(moze(umn, prosti[pbroj])) rekde(pbroj, umn * prosti[pbroj], 1);
    rekde(pbroj + 1, umn, 0);
    return;
}

int eva(long long int x)
{
    long long int ret = 0;
    int po = (int)desni.size() - 1;
    REP(i, 0, (int)lijevi.size())
    {
        while(1)
        {
            if(moze(lijevi[i], desni[po]))
            {
                if(lijevi[i] * desni[po] <= x) break;
                else po--;
            }
            else
            {
                po--;
            }
            if(po < 0) break;
        }
        ret += (long long) po + 1;
        if(po < 0) break;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    granica = n / 3;
    long long int x;
    REP(i, 0, n)
    {
        scanf("%lld", &x);
        prosti.push_back(x);
    }
    scanf("%lld", &k);
    rekli(0, 1, 1);
    rekde(granica + 1, 1, 1);
    sort(lijevi.begin(), lijevi.end());
    sort(desni.begin(), desni.end());
    long long int l = 0, r = 1e18, mid, vr;
    while(l < r)
    {
        mid = (l + r) / 2;
        vr = eva(mid);
        if(vr < k) l = mid + 1;
        else r = mid;
    }
    printf("%lld\n", l);
    return 0;
}