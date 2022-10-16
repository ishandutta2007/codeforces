#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int n;
int arr[110000];
int tree[110000];
int tree2[110000];


// tree1 (i) = maior ndice maior que i
int read(int a) {
    int s = -1;
    while (a <= n+10) {
        s = max(s, tree[a]);
        a += a&-a;
    }
    return s;
}

void update(int a, int delta) {
    while (a > 0) {
        tree[a] = max(tree[a], delta);
        a -= a&-a;
    }
}

//tree2 (i) = maior update com ndice maior que i.
int read2(int a) {
    int s = 0;
    while (a <= n+10) {
        s = max(s, tree2[a]);
        a += a&-a;
    }
    return s;
}

void update2(int a, int delta) {
    while (a > 0) {
        tree2[a] = max(tree2[a], delta);
        a -= a&-a;
    }
}

int main() {
    memset(tree,-1,sizeof(tree));

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i-1]);
        arr[i-1]++;
    }

    for (int i = 1; i <= n; i++) {
        int prevmax = read(arr[i-1]+1);
        
        update(arr[i-1], i);

        if (prevmax == -1) {
            update2(i, 0);
        }
        else {
            int r2 = read2(prevmax+1);
            //printf("i = %d prevmax = %d r2(%d) = %d up(%d) = %d\n", i, prevmax,prevmax+1,r2,i,r2+1);
            update2(i, r2 + 1);
        }
    }

    cout << read2(1) << endl;
}