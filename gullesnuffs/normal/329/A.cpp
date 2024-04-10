#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
char field[105][105];
bool possible[2][105];
vector<pair<int, int> > ans[2];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%s", field[i]);
        for(int j=0; j < n; ++j){
            if(field[i][j] == '.'){
                if(!possible[0][i]){
                    possible[0][i]=1;
                    ans[0].push_back(make_pair(i+1, j+1));
                }
                if(!possible[1][j]){
                    possible[1][j]=1;
                    ans[1].push_back(make_pair(i+1, j+1));
                }
            }
        }
    }
    for(int t=0; t < 2; ++t){
        bool ok=1;
        for(int i=0; i < n; ++i){
            if(!possible[t][i])
                ok=0;
        }
        if(ok){
            for(int i=0; i < n; ++i)
                printf("%d %d\n", ans[t][i].first, ans[t][i].second);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}