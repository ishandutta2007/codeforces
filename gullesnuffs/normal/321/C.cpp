#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;

vector<int> inc[100005];
int left[100005];
queue<int> leaves;
bool added[100005];
int sz[100005];
char rank[100005];
int in_tree[100005], in_treeN;
int parent[100005];
int next[100005];

void process_tree(int start_node, char currentRank){
    in_tree[0]=start_node;
    left[start_node]=0;
    parent[start_node]=-1;
    in_treeN=1;
    for(int k=0; k < in_treeN; ++k){
        int now=in_tree[k];
        int s=inc[now].size();
        next[now]=-1;
        for(int i=0; i < s; ++i){
            int j=inc[now][i];
            if(rank[j] != 0)
                continue;
            if(j == parent[now])
                continue;
            left[now]++;
            left[j]=1;
            in_tree[in_treeN++]=j;
            parent[j]=now;
        }
    }
    for(int k=0; k < in_treeN; ++k){
        int now=in_tree[k];
        added[now]=0;
    }
    for(int k=0; k < in_treeN; ++k){
        int now=in_tree[k];
        sz[now]=1;
        if(left[now] == 1){
            int S=inc[now].size();
            for(int c=0; c < S; ++c){
                int d=inc[now][c];
                if(rank[d])
                    continue;
                if(added[d])
                    continue;
                next[now]=d;
                break;
            }
            leaves.push(now);
            added[now]=1;
        }
    }
    while(!leaves.empty()){
        int now=leaves.front();
        leaves.pop();
        int s=inc[now].size();
        --left[now];
        for(int i=0; i < s; ++i){
            int j=inc[now][i];
            if(rank[j])
                continue;
            if(!added[j]){
                --left[j];
                sz[j] += sz[now];
                if(left[j] == 1){
                    int S=inc[j].size();
                    for(int c=0; c < S; ++c){
                        int d=inc[j][c];
                        if(rank[d])
                            continue;
                        if(added[d])
                            continue;
                        next[j]=d;
                        break;
                    }
                    leaves.push(j);
                    added[j]=true;
                }
            }
        }
    }
    int best=in_treeN+10, bestI=-1;
    for(int k=0; k < in_treeN; ++k){
        int now=in_tree[k];
        int s=inc[now].size();
        int m=in_treeN-1;
        for(int i=0; i < s; ++i){
            int j=inc[now][i];
            if(rank[j])
                continue;
            if(j == next[now])
                continue;
            m -= sz[j];
        }
        for(int i=0; i < s; ++i){
            int j=inc[now][i];
            if(rank[j])
                continue;
            if(j == next[now])
                continue;
            if(sz[j] > m)
                m=sz[j];
        }
        if(m < best){
            best=m;
            bestI=now;
        }
    }
    rank[bestI]=currentRank;
    int s=inc[bestI].size();
    for(int i=0; i < s; ++i){
        int j=inc[bestI][i];
        if(rank[j])
            continue;
        --left[j];
        process_tree(j, currentRank+1);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        left[i]=0;
        added[i]=0;
        sz[i]=1;
        rank[i]=0;
    }
    for(int i=0; i < n-1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        inc[a].push_back(b);
        inc[b].push_back(a);
        ++left[a];
        ++left[b];
    }
    process_tree(0, 'A');
    for(int i=0; i < n; ++i){
        char s[2];
        s[0]=rank[i];
        s[1]=0;
        printf("%s ", s);
    }
    return 0;
}