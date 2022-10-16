#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>

#define MAXL 5000010

using namespace std;

typedef unsigned long long hash;

hash h[MAXL], rh[MAXL], pow[MAXL];
hash B, C;
hash memo[MAXL];

int len, ind;

int l1, l2;

char s[MAXL];

hash V(char c) {
    if ('A' <= c && c <= 'Z') return c-'A';
    if ('a' <= c && c <= 'z') return c-'a'+26;
    return c-'0'+52;
}

void build_hash() {    
    h[0]=C;
    for (int i = 1; i <= len; i++) h[i] = B*h[i-1] + V(s[i-1]);
}

void build_reverse() {    
    rh[0]=C;
    for (int i = 1; i <= len; i++) rh[i] = B*rh[i-1] + V(s[len-i]);
}

hash code_hash(hash* h, int a, int b) {
    return h[b] - h[a]*pow[b-a];
}

hash degree(int st, int end) {
    //printf("st=%d end=%d\n",st,end);
    if (st>end) return 0;
    if (st==end) return 1;

    int mid = (st+end)/2;
    hash right = code_hash(h, mid+1, end+1);
    
    int lmid = mid;
    
    if ((st+end)%2 == 1) lmid++;
    //printf("mid=%d lmid=%d\n",mid,lmid);
    
    hash left = code_hash(rh, len-lmid, len);
    
    if (right != left) { 
    //printf("h1=%llu h2=%llu\n",right,left); 
    return 0;}
    else return 1 + memo[lmid-1];
}

int main() {
    scanf("%s", s);
    
    B=71; C=0;
    
    pow[0]=1;
    for (int i = 1; i < MAXL; i++) {
        pow[i]=pow[i-1]*B;
    }
    
    len = strlen(s);
    
    build_hash();
    build_reverse();
    
    hash ans = 0;
    
    //printf("d=%llu\n",rh[1]);
    for (ind = 0; ind < len; ind++) {
        //printf("i=%d\n",i);
        ans += (memo[ind]=degree(0,ind));
        //printf("\n");
    }
    printf("%llu\n", ans);
}