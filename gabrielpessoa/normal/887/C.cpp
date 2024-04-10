#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;

const int SIZE = 505;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

/* int find_set(int a) {
    if(a != ds[a]) {
        ds[a] = find_set(ds[a]);
    }
    return ds[a];
}

void union_set(int a, int b) {
    ds[find_set(a)] = find_set(b);
} */

int c[25];

bool check() {
    //for(int i = 1; i <= 24; i++) {
    //    printf("%d ", c[i]);
    //}
    //printf("\n");
    for(int i = 0; i < 6; i++) {
        int pos = i*4 + 1;
        if(c[pos] == c[pos+1] && c[pos+1] == c[pos+2] && c[pos+2] == c[pos+3]) {
            continue;
        }
        return false;
    }
    return true;
}

void faceSwap(int a, bool dir) {
    int temp1, temp2;
    if(a == 0) {
        temp1 = c[5];
        temp2 = c[6];
        if(dir) {
            c[5] = c[17];
            c[6] = c[18];
            c[17] = c[21];
            c[18] = c[22];
            c[21] = c[13];
            c[22] = c[14];
            c[13] = temp1;
            c[14] = temp2;
        } else {
            c[5] = c[13];
            c[6] = c[14];
            c[13] = c[21];
            c[14] = c[22];
            c[21] = c[17];
            c[22] = c[18];
            c[17] = temp1;
            c[18] = temp2;
        }
    } else if(a == 1) {
        temp1 = c[3];
        temp2 = c[4];
        if(dir) {
            c[3] = c[17];
            c[4] = c[19];
            c[17] = c[9];
            c[19] = c[10];
            c[9] = c[14];
            c[10] = c[16];
            c[14] = temp1;
            c[16] = temp2;
        } else {
            c[3] = c[14];
            c[4] = c[16];
            c[14] = c[9];
            c[16] = c[10];
            c[9] = c[17];
            c[10] = c[19];
            c[17] = temp1;
            c[19] = temp2;
        }
    } else if(a == 2) {
        temp1 = c[7];
        temp2 = c[8];
        if(dir) {
            c[7] = c[19];
            c[8] = c[20];
            c[19] = c[23];
            c[20] = c[24];
            c[23] = c[15];
            c[24] = c[16];
            c[15] = temp1;
            c[16] = temp2;
        } else {
            c[7] = c[15];
            c[8] = c[16];
            c[15] = c[23];
            c[16] = c[24];
            c[23] = c[19];
            c[24] = c[20];
            c[19] = temp1;
            c[20] = temp2;
        }
    } else if(a == 3) {
        temp1 = c[5];
        temp2 = c[7];
        if(dir) {
            c[5] = c[9];
            c[7] = c[11];
            c[9] = c[22];
            c[11] = c[24];
            c[22] = c[1];
            c[24] = c[3];
            c[1] = temp1;
            c[3] = temp2;
        } else {
            c[5] = c[1];
            c[7] = c[3];
            c[1] = c[22];
            c[3] = c[24];
            c[22] = c[9];
            c[24] = c[11];
            c[9] = temp1;
            c[11] = temp2;
        }
    }else if(a == 4) {
        temp1 = c[6];
        temp2 = c[8];
        if(dir) {
            c[6] = c[10];
            c[8] = c[12];
            c[10] = c[21];
            c[12] = c[23];
            c[21] = c[2];
            c[23] = c[4];
            c[2] = temp1;
            c[4] = temp2;
        } else {
            c[6] = c[2];
            c[8] = c[4];
            c[2] = c[21];
            c[4] = c[23];
            c[21] = c[10];
            c[23] = c[12];
            c[10] = temp1;
            c[12] = temp2;
        }
    }  else if(a == 5) {
        temp1 = c[1];
        temp2 = c[2];
        if(dir) {
            c[1] = c[18];
            c[2] = c[20];
            c[18] = c[11];
            c[20] = c[12];
            c[11] = c[13];
            c[12] = c[15];
            c[13] = temp1;
            c[15] = temp2;
        } else {
            c[1] = c[13];
            c[2] = c[15];
            c[13] = c[11];
            c[15] = c[12];
            c[11] = c[17];
            c[12] = c[19];
            c[18] = temp1;
            c[20] = temp2;
        }
    } else {
        puts("FUDEU");
    }
}

int main() {
    for(int i = 1; i <= 24; i++) {
        scanf("%d", &c[i]);
    }
    for(int i = 0; i < 6; i++) {
        faceSwap(i, true);
        //printf("Cor %d True: ", i);
        if(check()) {
            puts("YES");
            return 0;
        }
        faceSwap(i, false);
        faceSwap(i, false);
        //printf("Cor %d False: ", i);
        if(check()) {
            puts("YES");
            return 0;
        }
        faceSwap(i, true);
    }
    puts("NO");
    return 0;
}