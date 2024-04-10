#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <complex>
#include <stack>

using namespace std;

int n;
long long a[100005];
vector<int> adj[100005];
bool visited[100005];
int parent[100005];
queue<int> q;
stack<int> s;
int nodes[100005];
long long apples[100005];
long long minJump[100005];

long long gcd(long long a, long long b){
    return b?gcd(b, a%b):a;
}

long long lcm(long long a, long long b){
    return (a/gcd(a, b))*b;
}

int main() {
    scanf("%d", &n);
    long long start=0;
    for(int i=0; i < n; ++i){
        scanf("%I64d", a+i);
        start += a[i];
    }
    for(int i=0; i < n-1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(0);
    parent[0]=-1;
    s.push(0);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0; i < adj[cur].size(); ++i){
            if(adj[cur][i] == parent[cur])
                continue;
            parent[adj[cur][i]]=cur;
            s.push(adj[cur][i]);
            q.push(adj[cur][i]);
        }
    }
    while(!s.empty()){
        int cur=s.top();
        s.pop();
        if(adj[cur].size() == 1 && parent[cur] != -1){
            //Leaf
            nodes[cur]=1;
            apples[cur]=a[cur];
            minJump[cur]=1;
        }else{
            minJump[cur]=1;
            long long Min=999999999999999999LL;
            for(int i=0; i < adj[cur].size(); ++i){
                if(adj[cur][i] == parent[cur])
                    continue;
                if(apples[adj[cur][i]] < Min)
                    Min=apples[adj[cur][i]];
                double t=minJump[cur];
                t *= minJump[adj[cur][i]];
                t /= gcd(minJump[cur], minJump[adj[cur][i]]);
                if(t > Min*2){
                    minJump[cur]=Min+1;
                    break;
                }
                minJump[cur]=lcm(minJump[cur], minJump[adj[cur][i]]);
            }
            apples[cur]=(Min/minJump[cur])*minJump[cur];
            if(parent[cur] == -1)apples[cur] *= adj[cur].size();
            else apples[cur] *= adj[cur].size()-1;
            minJump[cur] *= adj[cur].size()-1;
        }
    }
    printf("%I64d", start-apples[0]);
    return 0;
}