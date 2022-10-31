#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#define N 300020
#define M 1000020
#define int long long
#pragma GCC optimize("O3")
using namespace std;

/*int f[M];
bool u[M];

void Prime(void)
{
    int i, j;

    u[1] = true;
    f[1] = 1;
    for(i = 2;i < M;i ++)
    {
        if(!u[i])
        {
            f[i] = 2;
            for(j = i * i;j < M;j += i)
            {
                u[j] = true;
                f[j] += 
            }
        }
    }

    return;
}*/

int num_prime = 0, MinPrime[M], MaxPrime[M];
int f[M], MinPrime_num[M];  
int prime[M], myresult;  
  

int a[N];
set<int> g;

int y[N], c;

void Prime(void)  
{  
    int i, j, len, tmp;  
//  i = 2;  
//  prime[len = MinPrime[i] = num_prime++] = i;  
    num_prime = 1;  
    for (i = 2; i < M; ++i)  
    {  
        if (!MinPrime[i])  
        {  
            prime[len = MinPrime[i] = num_prime++] = i;  
            MinPrime_num[i] = 1;      
            f[i] = 2;  
        }  
        else  
            len = MinPrime[i];  

        for (j = 1; j < len && (tmp = i * prime[j]) < M; ++j)  
        {  
            MinPrime[tmp] = j;  
            f[tmp] = f[i] << 1;  
            MinPrime_num[tmp] = 1;  
            //cout << tmp <<'\t' endl;  
        }  
  
        if (j == len && (tmp = i * prime[j]) < M)  
        {  
            MinPrime[tmp] = j;  
            MinPrime_num[tmp] = MinPrime_num[i] + 1;  
            f[tmp] = f[i] / MinPrime_num[tmp] * (MinPrime_num[tmp]+1);  
        }  
  
    }  

}  

namespace BIT
{
    int n, f[N], g[N];

    int Lowbit(int x)
    {
        return x & -x;
    }

    void Set(int p, int v)
    {
        int y = p;

        for(;p <= n;p += Lowbit(p))
            f[p] += v - g[y];
        g[y] = v;

        return;
    }

    int Sum(int p)
    {
        int o;

        /*puts("THT");
        for(int i=1;i<=n;i++)
            cout<<g[i]<<' ';
        puts("\n-----------");*/

        for(o = 0;p;p = p - Lowbit(p))
            o += f[p];

        return o;
    }

    void Init(int _n, int *a)
    {
        int i;

        n = _n;
        for(i = 1;i <= n;i ++)
            Set(i, a[i]);

        return;
    }
}

signed main()
{
    int n, m;
    int t, l, r;
    int i;
    set<int>::iterator h;

    Prime();
    scanf("%I64d %I64d", &n, &m);
    /*for(i=1;i<100;i++)
        cout<<f[i]<<' ';*/
    for(i = 1;i <= n;i ++)
    {
        scanf("%I64d", &a[i]);
        if(a[i] > 2)
            g.insert(i);
    }
    BIT::Init(n, a);

    while(m --)
    {
        scanf("%I64d %I64d %I64d", &t, &l, &r);
        if(t == 1)
        {
            h = g.lower_bound(l);
            c = 0;
            for(;h != g.end() && *h <= r;++ h)
            {
                t = BIT::g[*h];
                //printf("%I64d : %I64d -> %I64d\n",*h,t,f[t]);
                BIT::Set(*h, f[t]);
                if(f[t] < 3)
                    y[c ++] = *h;
            }

            for(i = 0;i < c;i ++)
                g.erase(y[i]);
        }
        else
            printf("%I64d\n", BIT::Sum(r) - BIT::Sum(l - 1));
    }

    return 0;
}