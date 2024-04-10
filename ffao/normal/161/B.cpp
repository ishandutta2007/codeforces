#include <stdio.h>
#include <algorithm>
#include <cstring>

int n, k;
using namespace std;

#define INF 1000000001

struct item {
    int cost;
    int id;
    
    bool operator< (item ot) const {
        return cost<ot.cost;
    }
};

item stools[1000];
int stc;
item pencil[1000];
int pc;

int stcart[1000];
int stcart2[1000];
int penccart[1000];

int c, t;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &t);
        if (t == 1) {
            stools[stc].id=i;
            stools[stc++].cost = c;
        }
        else {
            pencil[pc].id=i;
            pencil[pc++].cost = c;
        }
    }
    
    sort(stools,stools+stc);
    sort(pencil,pencil+pc);
    
    double tot = 0;
    
    int cur = k-1;
    for (int i = stc-1; i>=0; i--) {
        if (cur == 0 && i != 0) continue;
        stcart2[i]=cur;
        stcart[cur--] = stools[i].cost;
    }
    
    cur = k-1;
    for (int i = pc-1; i>=0; i--) {
        while (cur != 0 && (stcart[cur] > pencil[i].cost || cur > i)) cur--;
        
        penccart[i] = cur;
        if (stcart[cur] == 0 && cur != 0) {
            cur--;
        }
    }
    
    int st = stc-1;
    int penc = pc-1;
    for (int i = k-1; i>=0; i--) {
        int disc = INF;
        int from_st = st;
        while (st != -1 && stcart2[st] == i) {
            disc = min(disc,stools[st].cost);
            tot += stools[st].cost;
            st--;
        }
        int from_penc = penc;
        while (penc != -1 && penccart[penc] == i) {
            disc = min(disc,pencil[penc].cost);
            tot += pencil[penc].cost;
            penc--;
        }
        
        if (st != from_st) tot -= disc*0.5;
    }
    
    printf("%.1lf\n",tot);
    
    st = stc-1;
    penc = pc-1;
    for (int i = k-1; i>=0; i--) {
        int cnt = 0;
        int from_st = st;
        while (st != -1 && stcart2[st] == i) {
            st--;
            cnt++;
        }
        int from_penc = penc;
        while (penc != -1 && penccart[penc] == i) {
            penc--;
            cnt++;
        }
        
        printf("%d", cnt);
        for (int j = st+1; j <= from_st; j++) {
            printf(" %d", stools[j].id+1);
        }
        for (int j = penc+1; j <= from_penc; j++) {
            printf(" %d", pencil[j].id+1);
        }
        printf("\n");
    }
}