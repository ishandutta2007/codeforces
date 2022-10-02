

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;

set<pair<long long, int> > s;
long long d[100000];
vector<pair<long long,int> > v[100000];
long long a[100000];
#define INF 100000000001

void update(int i, long long l){
    s.erase(s.find(make_pair(d[i], i)));
    d[i] = l;
    s.insert(make_pair(d[i], i));
}

void dijkstra(){
    while(!s.empty()){
        int b = s.begin()->second;
        s.erase(s.begin());
        for(int i = 0; i < (int)v[b].size(); i++){
            long long c = d[b] + v[b][i].first;
            if(d[v[b][i].second] > c){
                update(v[b][i].second, c);
                a[v[b][i].second] = b;
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a != b){
            v[a - 1].push_back(make_pair(c, b - 1));
            v[b - 1].push_back(make_pair(c, a - 1));
        }
    }
    for(int i = 0; i < n; i++){
        d[i] = INF;
        s.insert(make_pair(INF, i));
        a[i] = INF;
    }
    update(0, 0);
    dijkstra();
    if(d[n - 1] == INF){
        cout << "-1\n";
        return 0;
    }
    vector<int> v2;
    int t = n - 1;
    while(t != 0){
        v2.push_back(t);
        t = a[t];
    }
    v2.push_back(0);
    for(int i = (int)v2.size() - 1; i >= 0; i--){
        cout << v2[i] + 1 << ' ';
    }
    cout << "\n";
    return 0;
}