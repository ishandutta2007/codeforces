
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
#define IN 1000
#define INF 1000000000001LL
long long d[IN];
vector<pair<int,int> > v[IN];

void update(int i, long long l){
    s.erase(s.find(make_pair(d[i], i)));
    d[i] = l;
    s.insert(make_pair(d[i], i));
}
vector<pair<int, int> > v2[IN];
bool b[IN];
int n;
int t[IN], c[IN];

void dijkstra(){
    while(!s.empty()){
        int b = s.begin()->second;
        s.erase(s.begin());
        for(int i = 0; i < (int)v[b].size(); i++){
            long long c = d[b] + v[b][i].first;
            if(d[v[b][i].second] > c){
                update(v[b][i].second, c);
            }
        }
    }
}

void dijkstra2(){
    for(int i = 0; i < n; i++){
   		int a = -1;
   		for(int j = 0; j < n; j++){
   			if(!b[j] && (a == -1 || (a != -1 && d[a] > d[j]))){
   				a = j;
   			}
   		}
   		if(a != -1){
   			b[a] = true;
   			for(int j = 0; j < (int)v2[a].size(); j++){
  				if(d[a] + v2[a][j].first < d[v2[a][j].second]){
   					d[v2[a][j].second] = d[a] + v2[a][j].first;
   				}
   			}
   		}
    }
}

int main() {
  int m;
  int x;
  int y;
  cin >> n >> m >> x >> y;
  for(int i = 0; i < m; i++){
    int a, b, c;
  	cin >> a >> b >> c;
  	v[a - 1].push_back(make_pair(c, b - 1));
    v[b - 1].push_back(make_pair(c, a - 1));
  }
  for(int i = 0; i < n; i++){
  	cin >> t[i] >> c[i];
  }
  for(int i = 0; i < n; i++){
  	for(int j = 0; j < n; j++){
        d[j] = INF;
    		s.insert(make_pair(INF, j));
    }
  	update(i, 0);
    dijkstra();
    for(int j = 0; j < n; j++){
      if(j != i && d[j] <= t[i]){
    		v2[i].push_back(make_pair(c[i], j));
    	}
    }
  }
  for(int i = 0; i < n; i++){
      d[i] = INF;
  	  b[i] = false;
  }
  d[x - 1] = 0;
  dijkstra2();
  if(d[y - 1] != INF){
      cout << d[y - 1] << "\n";
  }else{
  	  printf("-1\n");
  }
  return 0;
}