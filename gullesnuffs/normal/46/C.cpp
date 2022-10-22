#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

char in[1005];
int tN=0;

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", in);
    for(int i=0; in[i]; ++i)
        if(in[i] == 'T')
            ++tN;
    int ans=n;
    for(int s=0; s < n; ++s){
        int tot=0;
        for(int j=0; j < tN; ++j){
            if(in[(s+j)%n] == 'H')
                ++tot;
        }
        if(tot < ans)
            ans=tot;
    }
    printf("%d\n", ans);
    return 0;
}