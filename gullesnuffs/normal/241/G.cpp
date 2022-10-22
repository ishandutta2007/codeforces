#include <stdio.h>
#include <complex>
#include <map>
#define EPS 1e-8

using namespace std;

int main()
{
    //FILE *fout = fopen("answer.out", "w");
    printf("307\n");
    printf("0 500010\n");
    int pos=450000;
    for(int i=0; i < 305; ++i){
        printf("%d %d\n", pos, 310-i);
        pos += (310-i)*2;
    }
    printf("1000000 500010\n");
    //fclose(fout);
    return 0;
}