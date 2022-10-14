// Codeforces Beta Round #12
// Problem A -- Super Agent
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> graph;

int main()
{
    graph.resize(3);
    for(int i = 0; i != 3; ++ i)
        cin >> graph[i];
    bool flag = true;
    for(int i = 0; i != 3; ++ i)
        for(int j = 0; j != 3; ++ j)
            flag &= graph[i][j] == graph[2 - i][2 - j];
    cout << (flag ? "YES\n": "NO\n");
    return 0;
}