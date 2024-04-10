
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


set<pair<int, int> > s;
vector<pair<int, int> > v[100000];
int d[100000];
#define INF 1000000000

void update(int i, int r){
    s.erase(s.find(make_pair(d[i], i)));
    d[i] = r;
    s.insert(make_pair(d[i], i));
}

void dijkstra(){
    while(!s.empty()){
        int b = s.begin()->second;
        s.erase(s.begin());
        for(int i = 0; i < (int)v[b].size(); i++){
            int c = d[b] + v[b][i].first;
            if(d[v[b][i].second] > c){
                update(v[b][i].second, c);
            }
        }
    }
}

int main(){
    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < m; i++){
    	int a, b, c;
    	cin >> a >> b >> c;
    	v[a - 1].push_back(make_pair(c, b - 1));
    	v[b - 1].push_back(make_pair(c, a - 1));
    }
    int l;
    cin >> l;
    for(int i = 0; i < n; i++){
    	s.insert(make_pair(INF, i));
    	d[i] = INF;
    }
    update(t - 1, 0);
    dijkstra();
    int k = 0;
    map<pair<int, int>, bool> mm;
    for(int i = 0; i < n; i++){
    	if(d[i] == l){
    		k++;
    	}
    	for(int j = 0; j < (int)v[i].size(); j++){
    		if(v[i][j].first > l - d[i]){
    			if(d[i] < l){
    				if(d[i] + l - d[i] <= v[i][j].first - (l - d[i]) + d[v[i][j].second]){
    					k++;
    					mm[make_pair(i, v[i][j].second)] = true;
    				}
    			}
    		} 
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < (int)v[i].size(); j++){
    		if(v[i][j].first > l - d[i]){
    			if(d[i] < l){
    				if(d[i] + l - d[i] == v[i][j].first - (l - d[i]) + d[v[i][j].second] && mm[make_pair(i, v[i][j].second)] && mm[make_pair(v[i][j].second, i)]){
    					k--;
    					mm[make_pair(i, v[i][j].second)] = false;
    				}
    			}
    		} 
    	}
    }
    cout << k << "\n";
	return 0;
}