#include <stdio.h>
#include <algorithm>
#include <queue>
#define mod 1000000007

using namespace std;

queue<int> q[2];
int n;
int id[100005];
int next[100005];
bool dead[100005][2];

int main()
{
    scanf("%d", &n);
    bool read = 0, write=1;
    for(int i=0; i < n; ++i){
        scanf("%d", id+i);
        --id[i];
        dead[i][0] = 0;
        dead[i][1] = 0;
    }
    for(int i=n-2; i >= 0; --i){
        next[id[i]] = id[i+1];
        q[write].push(id[i]);
    }
    next[id[n-1]] = -1;
    int steps;
    for(steps = 0; true; ++steps){
        read ^= 1;
        write ^= 1;
        bool someoneDied = 0;
        while(!q[read].empty()){
            int now = q[read].front();
            q[read].pop();
            if(dead[now][read])
                continue;
            if(next[now] == -1)
                continue;
            if(now > next[now]){
                dead[next[now]][write]=1;
                next[now] = next[next[now]];
                q[write].push(now);
                someoneDied = 1;
            }
        }
        if(!someoneDied)
            break;
    }
    printf("%d", steps);
    return 0;
}