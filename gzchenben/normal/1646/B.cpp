#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int L=2,R=n;
        long long sumL=a[1],sumR=0;
        while(L<R)
        {
            sumL+=a[L];
            sumR+=a[R];
            L++;
            R--;
        }
        printf(sumL<sumR ? "YES\n" : "NO\n");
    }
}