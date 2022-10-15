#include <cstdio>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

typedef long long tint;

const int MAX = 1000000;

int xi[MAX];
int ti[MAX];
int who[MAX];
int res[MAX];

int foo(int i,int j)
{
    return xi[i] < xi[j];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    forn(i,n)
    {
        scanf("%d%d",ti+i,xi+i);
        who[i] = i;
    }
    
    int t = 0;
    int a = 0;
    while (a < n)
    {
        // Hacer un viaje completo
        int b = min(n, a + m);
        t = max(t,ti[b-1]); // esperamos al ultimo antes de partir
        sort(who+a,who+b,foo);
        int x = 0;
        for(int i=a, j; i < b; i = j)
        {
            for (j = i; j < b && xi[who[i]] == xi[who[j]];j++); // [i,j) es el cacho
            t += xi[who[i]] - x;
            forsn(k,i,j)
                res[who[k]] = t;
            t += 1 + (j-i) / 2;
            x = xi[who[i]];
        }
        t += x; // vuelta
        a = b;
    }
    
    
    forn(i,n)
    {
        if (i) printf(" ");
        printf("%d",res[i]);
    }
    printf("\n");
    return 0;
}