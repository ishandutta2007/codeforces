#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    int a,b,last = -1;
    queue<int> fila;
    scanf("%d %d",&a,&b);

    if(b > 2*a + 2 || a > b + 1) {
        printf("-1\n");
        return 0;
    }

    while(a || b) {
        if((a == b + 1 && last != 0)|| last == 2 || !b) {
            a--;
            printf("0");
            last = 0;
        }
        else {
            b--;
            printf("1");
            if(last == 1) last++;
            else last = 1;
        }
    }

    puts("");

    return 0;
}