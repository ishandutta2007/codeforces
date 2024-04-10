#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#define PLUS 0
#define MINUS 1
#define MULT 2

using namespace std;
int k, m;
int pw[10];
set<int> ans;

void rec(int ind, int numbers, int res){
    if(ind == 4){
        if(res < k && k-res < 10000){
            ans.insert(numbers*10000+k-res);
        }
        if(res >= k && res-k < 10000){
            ans.insert(numbers*10000+res-k);
        }
        return;
    }
    for(int i=1; i+ind < 5; ++i){
        for(int j=0; j < pw[i]; ++j){
            if(ind == 0){
                rec(i, j, j);
            }
            else{
                rec(ind+i, numbers*pw[i]+j, res+j);
                rec(ind+i, numbers*pw[i]+j, res-j);
                rec(ind+i, numbers*pw[i]+j, res*j);
            }
        }
    }
}

int main()
{
    pw[0]=1;
    for(int i=0; i < 9; ++i)
        pw[i+1]=pw[i]*10;
   scanf("%d%d", &k, &m);
   rec(0, 0, 0);
   for(set<int>::iterator it=ans.begin(); it != ans.end() && m; ++it, --m){
       int x=*it;
        for(int i=7; i >= 0; --i){
            printf("%d", x/pw[i]);
            x %= pw[i];
        }
        printf("\n");
   }
    return 0;
}