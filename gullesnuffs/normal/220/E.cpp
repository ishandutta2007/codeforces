#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int aN, a[100100];
long long invN;
pair<int, int> comp[100100];

struct fenwick{
    int a[140000];
    fenwick(){
        memset(a, 0, 140000);
    }
    void add(int p, int v){
        if(p > 130000)
            return;
        a[p] += v;
        add(p|(p+1), v);
    }
    int get(int p){
        int s=0;
        while(p != -1){
            s += a[p];
            p=((p+1)&p)-1;
        }
        return s;
    }
};

fenwick left, right;

int main()
{
    scanf("%d%I64d", &aN,&invN);
    for(int i=0; i < aN; ++i){
        scanf("%d", a+i);
        comp[i]=make_pair(a[i], i);
    }
    sort(comp, comp+aN);
    for(int i=0; i < aN; ++i)
        a[comp[i].second]=i;
    int lP, rP, sum=0;
    for(rP=aN-1; rP >= 0; --rP){
        int add=right.get(a[rP]);
        if(sum+add > invN)
            break;
        right.add(a[rP], 1);
        sum += add;
    }
    long long ans=0;
    ++rP;
    for(lP=0; lP < aN; ++lP){
        if(lP > 0)
            ans += min(aN-lP, aN-rP);
        sum += left.get(aN-a[lP])+right.get(a[lP]);
        left.add(aN-a[lP], 1);
        while(sum > invN && rP < aN){
            right.add(a[rP], -1);
            sum -= left.get(aN-a[rP])+right.get(a[rP]);
            ++rP;
        }
    }
    printf("%I64d", ans);
    return 0;
}