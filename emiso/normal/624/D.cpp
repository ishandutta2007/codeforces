#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>

#define INF 400000000000000000
#define MAXN 1000100

using namespace std;

set<int> divs;
int n,a,b,s[MAXN];
long long val[MAXN], totalval[MAXN],reval, prefix[MAXN], ans = INF;

void add_div(int l, int r){

    int psbl[6] = {l-1, l, l+1, r-1, r, r+1};

    for(int p=0;p<6;p++) {
        int divi = psbl[p];

        for(int i = 2; i*i <= psbl[p]; i++) {

            if(divi % i == 0) {
                divs.insert(i);

                while(divi % i == 0) divi /= i;
            }
        }

        divs.insert(divi);
    }
    divs.erase(1);
}

int main() {
    scanf("%d %d %d",&n,&a,&b);

    for(int i=0;i<n;i++) {
        scanf("%d",&s[i]);
    }

    add_div(s[0],s[n-1]);

    for(set<int>::iterator it = divs.begin(); it != divs.end(); it++) {

        for(int i=0; i<n; i++) {

            if(s[i] % *it == 0) val[i] = 0;
            else if((s[i] + 1) % *it == 0 || (s[i] - 1) % *it == 0)
                val[i] = b;
            else val[i] = INF;

            if(i==0) totalval[i] = val[i];
            else {
                totalval[i] = totalval[i-1] + val[i];
                if(totalval[i] > INF) totalval[i] = INF;
            }
        }

        reval = val[n-1];
        prefix[n-1] = min(reval,(long long) a);

        for(int i=n-2;i>=0;i--) {
            reval += val[i];
            if(reval > INF) reval = INF;
            prefix[i] = min(a + prefix[i+1], reval);
        //printf("prime %d, i %d, prefix %I64d\n",*it,i,prefix[i]);
        }

        ans = min(ans,prefix[0]);
        for(int i=1; i<n; i++) {
            //printf("prime %d, total val %I64d\n",*it,prefix[i] + totalval[i-1]);
            ans = min(ans,prefix[i] + totalval[i-1]);
        }
    }

    printf("%I64d\n",ans);

    return 0;
}