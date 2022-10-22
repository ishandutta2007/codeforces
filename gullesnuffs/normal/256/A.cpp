#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int b[4005], n;
vector<int> list[1000005];
vector<int> used;

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", b+i);
        if(list[b[i]].empty())
            used.push_back(b[i]);
        list[b[i]].push_back(i);
    }
    int best=0;
    for(int i=0; i < used.size(); ++i)
        for(int j=i; j < used.size(); ++j){
            int m=0;
            int pi=0, pj=0, vi=used[i], vj=used[j], last=-1;
            if(i == j)
                m=list[vi].size();
            else{
                while(pi < list[vi].size() || pj < list[vj].size()){
                    if(pi == list[vi].size() || (pj < list[vj].size() && list[vj][pj] < list[vi][pi])){
                        if(last != 1)
                            ++m;
                        ++pj;
                        last=1;
                    }
                    else{
                        if(last != 0)
                            ++m;
                        ++pi;
                        last=0;
                    }
                }
            }
            if(m > best)
                best=m;
        }
    printf("%d", best);
    return 0;
}