#include<bits/stdc++.h>
#define maxn 230405

using namespace std;
typedef long long ll;

ll n,k,m,query,d,p;
bool f;

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        scanf("%d",&n);
        if (n==0) printf("1 1\n");
        else {
            f=false;
            for (k=1;!f&&k<=100000;k++)
            {
                if (k*k<=n) continue;
                m=k*k-n;
                d=sqrt(m);
                if (d*d!=m) continue;
                p=k/d;
                if (k/p==d) {
                    cout << k << ' ' << p << endl;
                    f=true;
                }
            }
            if (!f) printf("-1\n");
        }
    }
    return 0;
}