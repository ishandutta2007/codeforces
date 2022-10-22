#include <stdio.h>

using namespace std;

char input[500];

int main()
{
    int a[4]={0,0,0,0};
    scanf("%s", input);
    for(int i=0; input[i]; ++i){
        if(input[i] == '+')
            continue;
        ++a[input[i]-'0'];
    }
    bool f=1;
    for(int i=1; i < 4; ++i){
        for(int j=0; j < a[i]; ++j){
            if(!f)
                printf("+");
            printf("%d", i);
            f=0;
        }
    }
    return 0;
}