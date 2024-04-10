#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{    
    int n, x[500000], v[500000];    
    scanf("%d", &n);
    for(int i = 0;i < n;++i)
        scanf("%d%d", &x[i], &v[i]);            
    bool fl = false;
    for(int i = 1;i < n;++i)
        fl = fl || v[i-1] > 0 && v[i] < 0;
    if(!fl)
        printf("-1\n");
    else
    {
        double a = 0, b = 1e9;        
        for(int it = 0;it < 70;++it)
        //while(b - a > 1e-12*max(b, 1))
        {
            long double t = 0.5*(a + b), r = -2e18;
            fl = true;
            for(int i = 0;i < n && fl;++i)
                if(v[i] > 0)
                    r = max(r, x[i] + v[i]*t);            
                else if(v[i] < 0 && x[i] + v[i]*t <= r + 1e-12)
                    fl = false;
            if(fl)
                a = t;
            else 
                b = t;
        }
        printf("%0.12llf\n", 0.5*(a + b));
    }
    return 0;
}