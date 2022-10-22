#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <complex>
#include <stack>

using namespace std;

int n;
int p[10000];
pair<int, int> P[10000];

struct Fenwick{
    int a[5000];
    void update(int pos, int val){
        for(; pos < 5000; pos|=(pos+1))
            a[pos] += val;
    }

    int query(int pos){
        int res=0;
        for(; pos >= 0; pos=(pos&(pos+1))-1)
            res += a[pos];
        return res;
    }
}fenwick;

int main() {
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", p+i);
        if(p[i] < 0)
            p[i]=-p[i];
        P[i]=make_pair(p[i], i);
    }
    sort(P, P+n);
    int ans=0;
    int nSame=1;
    for(int i=0; i < n; ++i){
        if(i && P[i].first == P[i-1].first)
            ++nSame;
        else
            nSame=1;
        int tot=fenwick.query(4000);
        int first=fenwick.query(P[i].second);
        tot += 1-nSame;
        first += 1-nSame;
        if(first*2 >= tot){
            ans += tot-first;
        }else{
            ans += first;
        }
        fenwick.update(P[i].second, 1);
    }
    printf("%d\n", ans);
    return 0;
}