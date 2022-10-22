#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>
#include <cstring>

using namespace std;

long long a[1000005];
long long d[2000000];
int number[2000000];
int dN;

int igcd(int a, int b){
    return b?igcd(b, a%b):a;
}

long long gcd(long long a, long long b){
    if(a < (1LL<<31) && b < (1LL<<31)){
        return b?igcd(b, a%b):a;
    }
    return b?gcd(b, a%b):a;
}

int main()
{
    int n;
    vector<long long> checked;
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        scanf("%I64d", a+i);
    long long best=1;
    for(int i=0; i < 162; ++i)
        rand();
    for(int i=0; i < 35; i += 3){
        long long m=a[(rand()%1000+1000*(rand()%1000))%n];
        bool ok=1;
        for(int j=0; j < checked.size(); ++j){
            if(checked[j]%m == 0){
                ok=0;
            }
        }
        if(m <= best)
            ok=0;
        if(!ok){
            i -= 2;
            continue;
        }
        checked.push_back(m);
        long long p=m;
        dN=1;
        d[0]=1;
        vector<long long> primes;
        for(long long j=2; j <= p; ++j){
            if(j*j > p)
                j=p;
            int times=0;
            while(p%j == 0){
                p/=j;
                ++times;
            }
            if(times)
                primes.push_back(j);
            for(int l=1; l <= times; ++l){
                for(int k=0; k < dN; ++k){
                    d[k+l*dN]=d[k+(l-1)*dN]*j;
                }
            }
            dN*=(times+1);
        }
        for(int j=0; j < dN; ++j)
            number[j]=0;
        sort(d, d+dN);
        for(int j=0; j < n; ++j){
            long long g=gcd(a[j], m);
            if(g <= best)
                continue;
            int Min=-1, Max=dN;
            while(Max-Min > 1){
                int test=(Max+Min)/2;
                if(g > d[test])
                    Min=test;
                else
                    Max=test;
            }
            ++number[Max];
            //++number[lower_bound(d, d+dN, g)-d];
        }
        for(int k=0; k < primes.size(); ++k){
            for(int j=dN-1; j >= 0; --j){
                if(d[j] <= best)
                    break;
                if(number[j]*2 >= n){
                    best=d[j];
                }
                if(d[j]%primes[k])
                    continue;
                long long lookFor=d[j]/primes[k];
                int Min=-1, Max=j;
                while(Max-Min > 1){
                    int test=(Max+Min)/2;
                    if(lookFor > d[test])
                        Min=test;
                    else
                        Max=test;
                }
                number[Max] += number[j];
            }
        }
    }
    printf("%I64d\n", best);
    return 0;
}