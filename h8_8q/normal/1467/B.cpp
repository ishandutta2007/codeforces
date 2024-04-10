#include <cstdio>
#include <cctype>
using namespace std;

const int max_n = 300000;
int a[max_n], incs[max_n] = {}, n;

#define gc getchar
inline int read()
{
    int c = gc(), t = 1, n = 0;
    while (isspace(c)) { c = gc(); }
    if (c == '-') { t = -1, c = gc(); }
    while (isdigit(c)) { n = n * 10 + c - '0', c = gc(); }
    return n * t;
}
#undef gc

inline int my_min(int u, int v) { return (u < v)? u:v; }

inline int incx(int i)
{
    if (i == 0 || i == n-1)
        return 0;

    return ((a[i-1] < a[i] && a[i] > a[i+1]) || (a[i-1] > a[i] && a[i] < a[i+1]));
}

int main()
{
    int cas = read(), iv, ta, ti, ans;

    while (cas--)
    {
        iv = ans = 0;

        n = read();
        for (int i = 0; i < n; i++)
            a[i] = read(),incs[i]=0;

        for (int i = 1; i < n-1; i++)
            iv += (incs[i] = incx(i));

    //  fprintf(stderr, "%d\n", iv);

        if (n >= 3)
        {
            ans = iv;

            for (int i = 1; i < n-1; i++)
            {
                ta = a[i];

                a[i] = a[i-1];
                ans = my_min(ans, iv - incs[i-1] - incs[i] - incs[i+1] + incx(i-1) + incx(i) + incx(i+1));

                a[i] = a[i+1];
                ans = my_min(ans, iv - incs[i-1] - incs[i] - incs[i+1] + incx(i-1) + incx(i) + incx(i+1));

                a[i] = ta;
            }
            //if(incx(1)||incx(n-2)) ans=my_min(ans,iv-1);
        }
		
        printf("%d\n", ans);
    }

    return 0;
}