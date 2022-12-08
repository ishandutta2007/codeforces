#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010000;

int N;

struct node {
    
public:
    
    int type;
    /*
    AND - 1
    OR  - 2
    XOR - 3
    NOT - 4
    IN  - 5
    */
    
    node() {
        used = false;
    }
    
    int child1, child2;
    int parent;
    
    bool status;
    bool used;
    
}graph[MAXN];
bool initial;
bool changes[MAXN];
int leaves[MAXN], leafctr;

void rdown(int n) {
    if(graph[n].used) return;
    graph[n].used = true;
    switch(graph[n].type)
    {
        case 1: case 2: case 3:
            rdown(graph[n].child1);
            rdown(graph[n].child2);
            break;
        case 4:
            rdown(graph[n].child1);
            break; 
        case 5: changes[n] = false; break;
        default: break;
    }
}
bool dfs(int n = 1) {
    bool a, b;
    switch(graph[n].type)
    {
        case 1: 
            a = dfs(graph[n].child1);
            b = dfs(graph[n].child2);
            if(!a) rdown(graph[n].child2);
            if(!b) rdown(graph[n].child1);
            graph[n].status = a and b;
            break;
        case 2:
            a = dfs(graph[n].child1);
            b = dfs(graph[n].child2);
            if(a) rdown(graph[n].child2);
            if(b) rdown(graph[n].child1);
            graph[n].status = a or b;
            break;
        case 3:
            a = dfs(graph[n].child1);
            b = dfs(graph[n].child2);
            graph[n].status = a xor b;
            break;
        case 4:
            a = dfs(graph[n].child1);
            graph[n].status = not a;
            break;
        case 5: break;
        default: break;
    }
    return graph[n].status;
}

int main() 
{
    
    cin >> N;
    leafctr = 0;
    for(int i = 1;i <= N;i++) {
        changes[i] = true;
        graph[i].used = false;
    }
    for(int i = 1;i <= N;i++)
    {
        string type;
        cin >> type;
        if(type == "AND")
        {
            int a, b;
            cin >> a >> b;
            graph[i].type = 1;
            graph[i].child1 = a;
            graph[i].child2 = b;
            graph[a].parent = i;
            graph[b].parent = i;
        }
        if(type == "OR")
        {
            int a, b;
            cin >> a >> b;
            graph[i].type = 2;
            graph[i].child1 = a;
            graph[i].child2 = b;
            graph[a].parent = i;
            graph[b].parent = i;
        }
        if(type == "XOR")
        {
            int a, b;
            cin >> a >> b;
            graph[i].type = 3;
            graph[i].child1 = a;
            graph[i].child2 = b;
            graph[a].parent = i;
            graph[b].parent = i;
        }
        if(type == "NOT")
        {
            int a;
            cin >> a;
            graph[i].type = 4;
            graph[i].child1 = a;
            graph[a].parent = i;
        }
        if(type == "IN")
        {
            int a;
            cin >> a;
            graph[i].type = 5;
            graph[i].status = a == 1;
            changes[i] = true;
            leaves[leafctr++] = i;
        }
    }
    
    initial = dfs();
    
    int ans = 0;
    for(int i = 0;i < leafctr;i++) {
        cout << (changes[leaves[i]] xor initial);
    }
    cout << endl;
    
}