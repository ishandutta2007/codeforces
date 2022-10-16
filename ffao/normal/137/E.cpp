#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <string.h>

using namespace std;

bool vow(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');  
}

#define NN 2100000

const int offset = 500000;

long long v[NN], c[NN];
char inp[1100000];
typedef long long tree[NN];
const int m = NN-10;

long long read(tree t, int x) {
    long long s = 0;
    while (x > 0) {
        s += t[x];
        x -= x&-x;
    }
    return s;    
}

void update(tree t, int x, long long delta) {
    while (x <= m) {
        t[x] += delta;
        x += x&-x;
    }
}

tree t;
int minimum[NN];

int main() {
    scanf("%s", inp);
    int len = strlen(inp);
    
    v[0] = 0;
    c[0] = 0;
    for (int i = 0; i < len; i++) {
        v[i+1] = v[i];
        c[i+1] = c[i];
        if (vow(inp[i])) v[i+1]++;
        else c[i+1]++;     
    }
    
    minimum[0] = offset;
    
    int best = 0, cnt = 0;
    
    for (int i = 0; i < len; i++) {
        int myval = 2*c[i+1] - v[i+1] + offset;
        minimum[i+1] = min(minimum[i], myval);
        
        int st = 0, ed = i;
        while (st < ed) {
            int m = (st+ed)/2;
            if (minimum[m] <= myval) ed = m;
            else st = m+1;
        }
        //printf("found %d: %d %d %d\n", st, minimum[st], myval, i-st+1);
        
        if (minimum[st] > myval) continue;
        if (i-st+1 == best) cnt++;
        else if (i-st+1 > best) {
            best = i-st+1;
            cnt = 1;
        }
    }
    
    //for (int i = 0; i <= len; i++) printf("%d\n", minimum[i]);
    
    if (cnt == 0) printf("No solution\n");
    else printf("%d %d\n", best, cnt);
}