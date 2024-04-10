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

int a[500005], b[500005];
int M[500005];
int occur[500005];
int ans[500005], ansN;
int k[500005];

int main()
{
    int n, m, p;
    ansN=0;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=0; i < n; ++i)
        scanf("%d", a+i);
    for(int i=0; i < m; ++i){
        scanf("%d", b+i);
    }
    sort(b, b+m);
    k[0]=1;
    occur[0]=0;
    occur[1]=1;
    for(int i=1; i < m; ++i){
        if(b[i] == b[i-1]){
            k[i]=k[i-1];
            ++occur[k[i]];
        }
        else{
            k[i]=k[i-1]+1;
            occur[k[i]]=1;
        }
    }
    for(int i=0; i < n; ++i){
        int Min=-1, Max=m;
        while(Max-Min > 1){
            int test=(Max+Min)/2;
            if(a[i] > b[test])
                Min=test;
            else
                Max=test;
        }
        if(Max < m && b[Max] == a[i])
            a[i]=k[Max];
        else
            a[i]=0;
    }

    for(int i=0; i < p; ++i){
        if((m-1) > (n-i-1)/p)
            continue;
        for(int j=0; j <= m; ++j)
            M[j]=0;
        int wrong=0;
        for(int j=0; j < m; ++j){
            if(M[a[i+j*p]] == occur[a[i+j*p]])
                ++wrong;
            ++M[a[i+j*p]];
        }
        if(!wrong)
            ans[ansN++]=i+1;
        for(int j=m; i+j*p < n; ++j){
            if(M[a[i+j*p]] == occur[a[i+j*p]])
                ++wrong;
            ++M[a[i+j*p]];
            if(M[a[i+(j-m)*p]] == occur[a[i+(j-m)*p]]+1)
                --wrong;
            --M[a[i+(j-m)*p]];
            if(!wrong){
                ans[ansN++]=i+(j+1-m)*p+1;
            }
        }
    }
    sort(ans, ans+ansN);
    printf("%d\n", ansN);
    for(int i=0; i < ansN; ++i)
        printf("%d ", ans[i]);
    return 0;
}