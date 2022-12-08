#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

int A, B;

void outpt(int * a) {
    printf("%d\n", a[0]);
    for(int i = 1;i <= a[0];i++) printf("%d ", a[i]);
    printf("\n");
}

const int MAXN = 1e5;
int a[MAXN], b[MAXN];

bool test(int ln) {
    if(static_cast<long long>(ln)*(ln + 1)/2 > A + B) return false;
    
    int ar = A, br = B;
    a[0] = b[0] = 0;
    
    for(int i = ln;i > 0;i--) {
        if(ar >= i) a[++a[0]] = i, ar -= i;
        else if(br >= i) b[++b[0]] = i, br -= i;
        else return false;
    }
    return true;
}


int main() {
    scanf("%d%d", &A, &B);
    
    int l = 0, h = MAXN;
    
    while(h > l + 1) {
        int m = l + ((h-l)>>1);
        if(static_cast<long long>(m)*(m + 1)/2 <= A + B) l = m;
        else h = m;
    }
    assert(test(l));
    
    outpt(a);
    outpt(b);
    
    return 0;
}