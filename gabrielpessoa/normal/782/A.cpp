#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, dum, cur = 0, m = 0;
    bool onTable[100005];
    memset(onTable, 0, sizeof(onTable));
    scanf("%d", &i);
    for(int j = 0; j < 2*i; j++) {
        scanf("%d", &dum);
        if(!onTable[dum]) {
            m = max(m, ++cur);
            onTable[dum] = true;
        } else {
            cur--;
        }
    }
    printf("%d", m);
	return 0;
}