#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#define OFFSET 100000
using namespace std;

vector<int> point[3][300005];
int x[100005], y[100005];
int ans;
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d%d", x+i, y+i);
		point[0][x[i]].push_back(y[i]);
		point[1][y[i]].push_back(x[i]);
		point[2][x[i]-y[i]+OFFSET].push_back(x[i]);
	}
	for(int i=0; i < 3; ++i)
		for(int j=0; j < 300005; ++j)
			sort(point[i][j].begin(), point[i][j].end());
	for(int i=0; i < n; ++i){
		int a[3]={x[i], y[i], x[i]-y[i]+OFFSET};
		int p[3]={0, 0, 0};
		int s[3]={-1, -1, -1};
		while(true){
			int Min=1000000;
			int Mini=-1;
			for(int j=0; j < 3; ++j){
				if(p[j] == point[j][a[j]].size()){
					s[j]=10000000;
					continue;
				}
				int side;
				int val=point[j][a[j]][p[j]];
				if(j == 0){
					side=val-y[i];
				}
				else if(j == 1){
					side=val-x[i];
				}
				else{
					side=val-x[i];
				}
				s[j]=side;
				if(side < Min){
					Min=side;
					Mini=j;
				}
			}
			if(Min > 999999)
				break;
			if(s[0] != 0 && s[0] == s[1] && s[0] == s[2])
				++ans;
			int other=min(s[(Mini+1)%3], s[(Mini+2)%3]);
			int MIN=p[Mini], MAX=point[Mini][a[Mini]].size();
			while(MAX-MIN > 1){
				int test=(MAX+MIN)/2;
				int val=point[Mini][a[Mini]][test];
				int side;
				if(Mini == 0){
					side=val-y[i];
				}
				else if(Mini == 1){
					side=val-x[i];
				}
				else{
					side=val-x[i];
				}
				if(side >= other)
					MAX=test;
				else
					MIN=test;
			}
			if(p[Mini] == MIN)
				p[Mini]=MAX;
			else
				p[Mini]=MIN;
		}
	}
	printf("%d\n", ans/2);
	return 0;
}