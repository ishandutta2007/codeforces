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
#define MAXP 1000

using namespace std;

int k;
bool primes[200000][100];
int okay[5000000];
int okayN;
int nLeft[MAXP];
bool isPrime[MAXP];
bool used[5000000];
vector<int> ans;

bool compare(int a, int b){
    if(nLeft[a] > nLeft[b])
        return 1;
    if(nLeft[a] < nLeft[b])
        return 0;
    return (a < b);
}

int main()
{
    scanf("%d", &k);
    okayN=1;
    okay[0]=1;
    isPrime[1]=0;
    for(int p=2; true; ++p){
        bool prime=1;
        for(int i=2; i*i <= p; ++i){
            if(p%i == 0)
                prime=0;
        }
        if(!prime){
            isPrime[p]=0;
            continue;
        }
        isPrime[p]=1;
        for(int i=okayN-1; i >= 0; --i){
            int j=okay[i]*p;
            while(j <= 2*k*k){
                for(int m=2; m < p; ++m)
                    primes[okayN][m]=primes[i][m];
                primes[okayN][p]=1;
                okay[okayN++]=j;
                j *= p;
            }
        }
        for(int i=2; i <= p; ++i)
            nLeft[i]=(k+1)/2;
        int need[MAXP];
        int needN=0;
        for(int i=2; i <= p; ++i)
            if(isPrime[i])
                need[needN++]=i;
        for(int i=0; i < okayN; ++i)
            used[i]=0;
        bool ok=1;
        bool anybad=0;
        ans.clear();
        while(ans.size() < k){
            int best=0;
            for(int i=1; i < okayN; ++i){
                if(used[i])
                    continue;
                for(int j=0; j < needN; ++j){
                    if(primes[i][need[j]] && !primes[best][need[j]]){
                        best=i;
                        break;
                    }
                    if(!primes[i][need[j]] && primes[best][need[j]]){
                        break;
                    }
                }
            }
            ans.push_back(okay[best]);
            if(used[best]){
                ok=0;
                break;
            }
            used[best]=1;
            anybad=0;
            for(int j=0; j < needN; ++j){
                if(nLeft[need[j]])
                    anybad=1;
                if(primes[best][need[j]] && nLeft[need[j]])
                    --nLeft[need[j]];
            }
            sort(need, need+needN, compare);
        }
        if(ok && !anybad){
            for(int i=0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            return 0;
        }
    }
    /*for(int maxp=2; true; maxp++){
        int cnt=0;
        for(int i=1; i < 1000000; ++i){
            int j=i;
            for(int k=2; k <= maxp; ++k){
                while(j%k == 0)
                    j /= k;
            }
            if(j == 1)
                ++cnt;
        }
        printf("%d: %d\n", maxp, cnt);
    }*/
    return 0;
}