#include <stdio.h>

using namespace std;

int l[100005], r[100005], t[100005];

int main()
{
    int n, m, s, f;
    scanf("%d%d%d%d", &n, &m, &s, &f);
    for(int i=0; i < m; ++i){
        scanf("%d%d%d", t+i, l+i, r+i);
    }
    int ind=0, pos=s, j, dir, c;
    if(f > s){
        dir=1;
        c=1;
    }
    else{
        dir=-1;
        c=0;
    }

    for(j=1; pos != f; ++j){
        if(t[ind] != j || l[ind] > pos+c || r[ind] < pos+c-1){
            if(dir == 1)
                printf("R");
            else
                printf("L");
            pos += dir;
        }else{
            printf("X");
        }
        if(t[ind] == j)
            ++ind;
    }
    return 0;
}