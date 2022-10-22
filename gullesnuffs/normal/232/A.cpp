#include <stdio.h>

using namespace std;
char answer[101][102];

int main()
{
    int k, completeN, addN;
    scanf("%d", &k);
    for(completeN=1; completeN*(completeN-1)*(completeN-2) <= k*6; ++completeN);
    --completeN;
    for(int i=0; i < 100; ++i){
        for(int j=0; j < 100; ++j)
            answer[i][j]='0';
        answer[i][100]=0;
    }
    for(int i=0; i < completeN; ++i){
        for(int j=0; j < completeN; ++j)
                answer[i][j]='1';
        answer[i][i]='0';
    }
    k -= (completeN*(completeN-1)*(completeN-2))/6;
    int pos=completeN;
    while(pos < 100){
        for(addN=1; (addN*(addN-1))/2 <= k && addN < completeN; ++addN);
        --addN;
        for(int i=0; i < addN; ++i){
            answer[pos][i]='1';
            answer[i][pos]='1';
        }
        k -= (addN*(addN-1))/2;
        ++pos;
    }
    printf("100\n");
    for(int i=0; i < 100; ++i)
        printf("%s\n", answer[i]);
    return 0;
}