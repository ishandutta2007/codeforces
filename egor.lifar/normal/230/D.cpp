
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

set <pair<long long, int>  >s;
vector<pair<int, int> > v[100100];
long long k[100100], d[100100], n;
vector<long long> t[100100];
#define INF 10000000000LL

void update(int i, long long l){
    s.erase(make_pair(d[i], i));
    d[i] = l;
    s.insert(make_pair(d[i], i));
}
bool r[100100];


void djikstra(){
	while(!s.empty()){
		long long b = s.begin()->second;
		if(r[b]){
			break;
		}
		r[b] = true;
		s.erase(s.begin());
		if(b != n - 1){
			while(binary_search(t[b].begin(), t[b].end(), d[b])){
				d[b] += 1;
			}
		}
		for(int i = 0; i < (int)v[b].size(); i++){
         	long long c = d[b] + v[b][i].first;
       	    if(d[v[b][i].second] > c){
           	    update(v[b][i].second, c);
           	}
       	}
	}
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int a, b, c;
    	cin >> a >> b >> c;
    	v[a - 1].push_back(make_pair(c, b - 1));
    	v[b - 1].push_back(make_pair(c, a - 1));
    }
    for(int i = 0; i < n; i++){
    	cin >> k[i];
    	for(int j = 0; j < k[i]; j++){
    		int a;
    		cin >> a;
    		t[i].push_back(a);
    	}
    }
    for(int i = 0; i < n; i++){
    	d[i] = INF;
    	s.insert(make_pair(INF, i));
    }
    update(0, 0);
    djikstra();
   

    if(d[n - 1] != INF){
    	cout << d[n - 1] << "\n";
    }else {
    	cout << "-1\n";
    }
	return 0;
}