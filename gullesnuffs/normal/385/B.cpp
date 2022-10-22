#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <complex>
#include <cassert>
using namespace std;

char input[5005];
bool bear[5005];

int main()
{
    scanf("%s", input);
    int len=strlen(input);
    int f=10000, e=-1000;
    for(int i=0; i < len-3; ++i){
        if(input[i] == 'b' && input[i+1] == 'e' && input[i+2] == 'a' && input[i+3] == 'r'){
            bear[i]=1;
            if(i < f)
                f=i;
            if(i > e)
                e=i;
        }
        else
            bear[i]=0;
    }
    int ans=0;
    for(int i=0; i < len; ++i){
        bool good=0;
        for(int j=i+4; j <= len; ++j){
            if(bear[j-4])
                good=1;
            ans += good;
        }
    }
    printf("%d\n", ans);
    return 0;
}