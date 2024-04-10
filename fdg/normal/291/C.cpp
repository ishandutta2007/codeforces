#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

unsigned int ip[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d\n",&n,&k);
    for(int i=0;i<n;++i) {
        int a,b,c,d;
        scanf("%d.%d.%d.%d\n",&a,&b,&c,&d);
        ip[i]=(((a<<8)|b)<<8)|c; ip[i]=(ip[i]<<8)|d;
    }
    unsigned int mask=1; mask<<=31;
    for(int i=30;i>=-1;--i) {
        set <unsigned int> f;
        for(int j=0;j<n;++j) {
            f.insert(mask&ip[j]);
            if (f.size()>k) break;
        }
        if (f.size()==k) {
            int d=mask&255,b,c,a;
            mask>>=8; c=mask&255;
            mask>>=8; b=mask&255;
            mask>>=8; a=mask;
            printf("%d.%d.%d.%d\n",a,b,c,d);
            return 0;
        }
        if (i>=0)
            mask|=(1u<<i);
    }
    printf("-1\n");
    return 0;
}