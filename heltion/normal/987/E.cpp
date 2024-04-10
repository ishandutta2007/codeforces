#include<bits/stdc++.h>
using namespace std;
#define maxn 1000001
int a[maxn], p[maxn];
int main(){
    int n, c = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i += 1){
        scanf("%d", a + i);
        p[a[i]] = i;
    }
    c = 0;
    for(int i = 1; i <= n; i += 1) if(a[i] != i){
        c += 1;
        int t = p[i];
        swap(p[i], p[a[i]]);
        swap(a[t], a[i]);
    }
    if((c ^ n) & 1) printf("Um_nik");
    else printf("Petr");   
}