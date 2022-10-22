#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

int F[200], FN, s, k;

vector<int> ans;

void rec(int num){
    if(!num)
        return;
    int p;
    p=upper_bound(F+1, F+FN, num)-F-1;
    ans.push_back(F[p]);
    rec(num-F[p]);
}

int main()
{
    scanf("%d%d", &s, &k);
    F[0]=1;
    for(FN=1; F[FN-1] <= 1e9; ++FN){
        F[FN]=0;
        for(int j=FN-1; j >= 0 && j >= FN-k; --j)
            F[FN] += F[j];
    }
    rec(s);
    if(ans.size() == 1)
        ans.push_back(0);
    printf("%d\n", ans.size());
    for(int i=0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    return 0;
}