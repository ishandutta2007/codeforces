#include <cstdio>

using namespace std;

int n, maxl, maxr, max1, max2, maxi1, maxi2;
int a[500011];
long long ans;
bool ismaxl[500011], ismaxr[500011];

int main() {
    scanf("%d", &n);
    if (n<=2) {
        printf("0");
        return 0;
    }
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) {
        if (a[i]>max1) max2=max1, max1=a[i], maxi2=maxi1, maxi1=i;
        else if (a[i]>max2) max2=a[i], maxi2=i;
    }
    ans-=2*max1+max2;
    for (int i=0; i<n; i++) {
        if (a[i]>=maxl) maxl=a[i], ans+=a[i], ismaxl[i]=true;
    }
    for (int i=n-1; i>=0; i--) {
        if (a[i]>maxr) maxr=a[i], ans+=a[i], ismaxr[i]=true;
    }
    for (int i=0; i<n; i++) {
        if (i>0) if (a[i]>=a[i-1]) if (!ismaxl[i]) ans+=a[i];
        if (i<n-1) if (a[i]>a[i+1]) if (!ismaxr[i]) ans+=a[i];
    }
    printf("%I64d", ans);
    return 0;
}