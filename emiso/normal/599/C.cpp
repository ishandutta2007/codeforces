#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

map <int,int> mapa;
int h[100100],bit[100100];

void update(int idx,int delta) {
    while(idx < 100100) {
        bit[idx] += delta;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main() {
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%d",&h[i]);
        mapa.insert(make_pair(h[i],0));
    }
    int i = 1;
    for(map<int,int>::iterator it = mapa.begin(); it != mapa.end(); it++) {
        it->second = i;
        i++;
    }
    for(int i=0;i<n;i++) {
        h[i] = mapa[h[i]];
        update(h[i],1);
    }

    int ans = 0;
    int maior = 0;

    for(int i=0;i<n;i++) {
        if(h[i] > maior) maior = h[i];
        update(h[i],-1);

        if(query(maior-1) == 0) {
            ans++;
            maior = h[i+1];
        }
    }

    printf("%d\n",ans);
    return 0;
}