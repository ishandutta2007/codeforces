

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


typedef int Distance;

struct edge{
    int a, k, t; 
};
set<pair<Distance, int> > s;
Distance d[300000]; 
vector<edge> v[300000];
vector<int> v2;
Distance a[300000], w[300000];
Distance xx[300000], dd[300000], tt[300000], pp[300000];
#define INF 1000000000

int getposition(int x){
   return (int)distance(v2.begin(), lower_bound(v2.begin(), v2.end(), x));
}

void update(int i, Distance l){
    s.erase(s.find(make_pair(d[i], i)));
    d[i] = l;
    s.insert(make_pair(d[i], i));
}

edge make_edge(int x, int y, int z){
    edge t;
    t.a = x;
    t.k = y;
    t.t = z;
    return t;
}

void dijkstra(){
    while(!s.empty()){
        int b = s.begin()->second;
        s.erase(s.begin());
        for(int i = 0; i < (int)v[b].size(); i++){
            Distance c = d[b] + v[b][i].a;
            if(d[v[b][i].k] > c){
                update(v[b][i].k, c);
                a[v[b][i].k] = b;
                w[v[b][i].k] = i;
            }
        }
    }
}

int main(){
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> xx[i] >> dd[i] >> tt[i] >> pp[i];
        if(xx[i] - pp[i] >= 0){
            v2.push_back(xx[i] - pp[i]);
            v2.push_back(xx[i] + dd[i]);
        }
    }
    v2.push_back(0);
    v2.push_back(l);
    sort(v2.begin(), v2.end());
    vector<int>::iterator it; 
    it = unique(v2.begin(), v2.end()); 
    v2.resize(distance(v2.begin(), it));
    for(int i = 0; i < n; i++){
        if(xx[i] - pp[i] >= 0){
            v[getposition(xx[i] - pp[i])].push_back(make_edge(tt[i] + pp[i], getposition(xx[i] + dd[i]), i));
        }
    }
    for(int i = 0; i < (int)v2.size() - 1; i++){
        v[i].push_back(make_edge(v2[i + 1] - v2[i], i + 1, -1));
        v[i + 1].push_back(make_edge(v2[i + 1] - v2[i], i, -1));
    }
    for(int i = 0; i < (int)v2.size(); i++){
        d[i] = INF;
        s.insert(make_pair(INF, i));
    }
    update(0, 0);
    dijkstra();
    printf("%d\n", d[(int)v2.size() - 1]);
    int s = (int)v2.size() - 1;
    vector<int> v3;
    while(s != 0){
        if(v[a[s]][w[s]].t != -1){
            v3.push_back(v[a[s]][w[s]].t);
        }
        s = a[s];
    }
    printf("%d\n", (int)v3.size());
    for(int i = (int)v3.size() - 1; i >= 0; i--){
        printf("%d ", v3[i] + 1);
    }
    printf("\n");
    return 0;
}