#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#define MAXN 200000

using namespace std;

int a[100005];

struct Fenwick{
    int a[MAXN];
    Fenwick(){
        for(int i=0; i < MAXN; ++i)
            a[i]=0;
    }
    void update(int i, int c){
        for(; i < MAXN; i |= i+1){
            a[i]=max(c, a[i]);
        }
    }
    int query(int i){
        int ret=0;
        for(; i >= 0; i=(i&(i+1))-1)
            ret=max(ret, a[i]);
        return ret;
    }
} fenwick;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
        fenwick.update(a[i], fenwick.query(a[i])+1);
    }
    printf("%d", fenwick.query(n));
    return 0;
}