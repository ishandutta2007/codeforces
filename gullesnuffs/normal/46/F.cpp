#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>

using namespace std;

pair<int, int> key[1005];
map<string, int> person;
int personRoom[1005][2];
vector<int> personKey[1005][2];
int Comp[1005];
bool hasKey[1005][1005];
int n, m, k;

bool dfs(int t){
    for(int i=0; i < n; ++i){
        Comp[i]=i;
        for(int j=0; j < m; ++j)
            hasKey[i][j]=0;
    }
    for(int i=0; i < k; ++i){
        for(int j=0; j < personKey[i][t].size(); ++j){
            hasKey[personRoom[i][t]][personKey[i][t][j]]=1;
        }
    }
    while(true){
        bool any=0;
        for(int i=0; i < m; ++i){
            int a=key[i].first, b=key[i].second;
            if(hasKey[a][i] || hasKey[b][i]){
                if(Comp[a] == Comp[b])
                    continue;
                any=1;
                int newComp=Comp[a];
                int bComp=Comp[b];
                vector<int> newKeysA, newKeysB;
                for(int l=0; l < m; ++l){
                    if(hasKey[a][l] && !hasKey[b][l])
                        newKeysB.push_back(l);
                    if(!hasKey[a][l] && hasKey[b][l])
                        newKeysA.push_back(l);
                }
                for(int j=0; j < n; ++j){
                    if(Comp[j] == Comp[a]){
                        Comp[j]=newComp;
                        for(int l=0; l < newKeysA.size(); ++l)
                            hasKey[j][newKeysA[l]]=1;
                    }
                    if(Comp[j] == bComp){
                        Comp[j]=newComp;
                        for(int l=0; l < newKeysB.size(); ++l)
                            hasKey[j][newKeysB[l]]=1;
                    }
                }
            }
        }
        if(!any)
            break;
    }
    for(int i=0; i < k; ++i){
        if(Comp[personRoom[i][t]] != Comp[personRoom[i][1-t]])
            return 0;
        for(int j=0; j < personKey[i][1-t].size(); ++j){
            if(!hasKey[personRoom[i][t]][personKey[i][1-t][j]] || !hasKey[personRoom[i][1-t]][personKey[i][1-t][j]])
                return 0;
        }
    }
    return 1;
}

int main()
{
    cin >> n >> m >> k;
    for(int i=0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        key[i]=make_pair(a, b);
    }
    for(int i=0; i < k; ++i){
        string name;
        cin >> name;
        person[name]=i;
        cin >> personRoom[i][0];
        --personRoom[i][0];
        int kN;
        cin >> kN;
        for(int j=0; j < kN; ++j){
            int a;
            cin >> a;
            personKey[i][0].push_back(a-1);
        }
    }
    for(int l=0; l < k; ++l){
        string name;
        cin >> name;
        int i=person[name];
        cin >> personRoom[i][1];
        --personRoom[i][1];
        int kN;
        cin >> kN;
        for(int j=0; j < kN; ++j){
            int a;
            cin >> a;
            personKey[i][1].push_back(a-1);
        }
    }
    if(dfs(0) && dfs(1))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}