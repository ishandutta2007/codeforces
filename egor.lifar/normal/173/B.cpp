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

queue <pair<int, int> > s;
int d[4000000];
int n, m;
#define INF 1000000000
string s2[10000];
int dy[4], dx[4];

bool kletka(int a, int b){
	return a < n && b < m && a >= 0 && b >= 0;
}

void update(int i, int r){
    d[i] = r;
    s.push(make_pair(d[i], i));
}

void bfs(){
    while(!s.empty()){
        int b = s.front().second;
        s.pop();
        int x = (b / 4) % m;
        int y = (b / 4) / m;
        int t = b % 4;
        if(s2[y][x] == '#'){
        	if(kletka(y + dy[t], x + dx[t]) && d[((x + dx[t]) + (y + dy[t]) * m) * 4 + t] > d[b]){
            	update(((x + dx[t]) + (y + dy[t]) * m) * 4 + t, d[b]);	
            }
            for(int i = 0; i < 4; i++){
            	if(i != t){
            		if(kletka(y + dy[i], x + dx[i]) && d[((x + dx[i]) + (y + dy[i]) * m) * 4 + i] > d[b] + 1){
            			update(((x + dx[i]) + (y + dy[i]) * m) * 4 + i, d[b] + 1);	
           		    }
            	}	
            	if(d[b - t + i] > d[b] + 1){
            		update(b - t + i,  d[b] + 1);	
           	    }
            }
        }else{
        	if(kletka(y + dy[t], x + dx[t]) && d[((x + dx[t]) + (y + dy[t]) * m) * 4 + t] > d[b]){
            	update(((x + dx[t]) + (y + dy[t]) * m) * 4 + t, d[b]);	
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> s2[i];
    }
    for(int i = 0; i < 4 * n * m; i++){
    	d[i] = INF;
    }
    update(4  * n * m - 3, 0);
    dx[0] = 0;
    dy[0] = -1;
    dx[1] = -1;
    dy[1] = 0;
    dx[2] = 0;
    dy[2] = 1;
    dx[3] = 1;
    dy[3] = 0; 
    bfs();
    if(d[1] != INF){
    	cout << d[1] << "\n";
	}else {
		cout << "-1\n";
	}
	return 0;
}