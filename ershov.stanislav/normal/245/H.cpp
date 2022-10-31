#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

char s[5001];
int q, len, pal[10000];
long long cnt[5000][5000];
long long power[5000], hash1[5001], hash2[5001];

int main() {
    scanf("%s%d", s, &q);
    len=(int)strlen(s);
    for (long long i=0, j=1; i<5011; i++, j*=37) power[i]=j;
    long long a=0, b=0;
    for (int i=0; i<=len; i++) {
        hash1[i]=a;
        hash2[i]=b;
        if (i<len) {
            a+=s[i]*power[i];
            b+=s[i]*power[len-i-1];
        }
    }
    for (int i=0; i<2*len-1; i++) {
        int l=max(0, i-len+1), r=i/2;
        while (l!=r) {
            int mid=(l+r)/2;
            if ((hash1[i-mid+1]-hash1[mid])*power[len-i+mid]==(hash2[i-mid+1]-hash2[mid])*power[mid+1]) r=mid;
            else l=mid+1;
        }
        if ((hash1[i-l+1]-hash1[l])*power[len-i+l]!=(hash2[i-l+1]-hash2[l])*power[l+1]) l++;
        pal[i]=l;
    }
    for (int i=0; i<len; i++) cnt[i][i]=1;
    for (int l=1; l<len; l++) for (int i=0; i<len-l; i++) {
        cnt[i][i+l]=cnt[i][i+l-1]+cnt[i+1][i+l]-cnt[i+1][i+l-1] + (pal[2*i+l]<=i);
    }
    for (int i=0; i<q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%I64d\n", cnt[--a][--b]);
    }
    return 0;
}