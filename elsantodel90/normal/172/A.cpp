#include <cstdio>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

const int MAX = 32;

char cand[MAX];

int main()
{
    int n; scanf("%d",&n);
    scanf("%s",cand);
    forn(i,n-1)
    {
        static char aux[MAX];
        scanf("%s",aux);
        int j;
        for (j=0; cand[j] && aux[j] && aux[j] == cand[j];j++);
        cand[j] = 0;
    }
    printf("%d\n",strlen(cand));
    return 0;
}