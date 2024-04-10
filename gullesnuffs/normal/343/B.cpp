#include <cstdio>
#include <cmath>

using namespace std;

char input[1000005];
int pre[1000005];

int main(){
    scanf("%s", input+1);
    input[0]='*';
    int i;
    for(i=0; input[i]; ++i){
        pre[i]=i-1;
    }
    pre[i]=i-1;
    pre[i+1]=i;
    for(i=0; input[i+1]; ++i){
        if(input[i+1] == input[pre[i+1]]){
            pre[i+2]=pre[pre[i+1]];
        }
    }
    if(pre[i+1] == 0)
        printf("Yes");
    else
        printf("No");
    return 0;
}