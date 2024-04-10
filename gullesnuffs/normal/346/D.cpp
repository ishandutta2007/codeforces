#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

vector<int> inAdj[1000005], outAdj[1000005];
int n, m;
queue<int> added, freeAdd, costAdd;
int edgesLeft[1000005];
bool processed[1000005];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;--b;
        outAdj[a].push_back(b);
        inAdj[b].push_back(a);
        ++edgesLeft[a];
    }
    for(int i=0; i < n; ++i)
        processed[i]=0;
    int s, t;
    scanf("%d%d", &s, &t);
    --s;--t;
    freeAdd.push(t);
    for(int cost=0; true; ++cost){
        while(!freeAdd.empty()){
            int c=freeAdd.front();
            freeAdd.pop();
            if(processed[c])
                continue;
            for(int i=0; i < inAdj[c].size(); ++i){
                if(edgesLeft[inAdj[c][i]] == outAdj[inAdj[c][i]].size())
                    costAdd.push(inAdj[c][i]);
                --edgesLeft[inAdj[c][i]];
                if(!edgesLeft[inAdj[c][i]])
                    freeAdd.push(inAdj[c][i]);
            }
            if(c == s){
                printf("%d\n", cost);
                return 0;
            }
            processed[c]=1;
            added.push(c);
        }
        while(!costAdd.empty()){
            int c=costAdd.front();
            costAdd.pop();
            freeAdd.push(c);
        }
        if(freeAdd.empty())
            break;
    }
    printf("-1\n");
    return 0;
}