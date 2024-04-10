#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int a[2005][2005];
int b[2005];
int main(){
	int n;
	scanf("%d", &n);
	int good=0;
	for(int i=0; i < n; ++i){
		for(int j=0; j < n; ++j){
			scanf("%d", a[i]+j);
			if(a[i][j])
				++b[i];
		}
		if(!b[i]){
			printf("NO\n");
			return 0;
		}
		if(b[i] > 1)
			good=1;
	}
	if(good){
		set<int> S;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int c=q.front();
			q.pop();
			for(int i=0; i < n; ++i)
				if(a[c][i]){
					if(S.find(i) == S.end()){
						S.insert(i);
						q.push(i);
					}
				}
		}
		if(S.size() < n){
			puts("NO");
			return 0;
		}
		S.clear();
		q.push(0);
		while(!q.empty()){
			int c=q.front();
			q.pop();
			for(int i=0; i < n; ++i)
				if(a[i][c]){
					if(S.find(i) == S.end()){
						S.insert(i);
						q.push(i);
					}
				}
		}
		if(S.size() < n){
			puts("NO");
			return 0;
		}
		puts("YES");
	}
	else
		printf("NO\n");
	return 0;
}