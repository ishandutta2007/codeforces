#include <stdio.h>
#include <vector>

using namespace std;

vector<int> know[105];
int belong[105];

int main()
{
   int n, m;
   bool allZero=true;
   scanf("%d%d", &n, &m);
   for(int i=0; i < n; ++i){
        int k;
        scanf("%d", &k);
        for(int j=0; j < k; ++j){
            int p;
            scanf("%d", &p);
            know[i].push_back(p);
        }
        if(k)
            allZero=false;
        belong[i]=i;
   }
   if(allZero){
        printf("%d", n);
        return 0;
   }
   for(int i=0; i < n; ++i)
       for(int j=i+1; j < n; ++j){
            int si=know[i].size(), sj=know[j].size();
            for(int k=0; k < si; ++k)
                for(int p=0; p < sj; ++p){
                    if(know[i][k] == know[j][p]){
                        for(int q=0; q < n; ++q)
                            if(belong[q] == belong[j])
                                belong[q]=belong[i];
                        break;
                    }
                }
       }
    int ans=-1;
    for(int i=0; i < n; ++i)
        if(belong[i] == i)
            ++ans;
    printf("%d", ans);
    return 0;
}