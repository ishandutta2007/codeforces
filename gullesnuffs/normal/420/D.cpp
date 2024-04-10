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
using namespace std;

int tree[10000000];
int pos[1000005];
int offset;
int children[10000000];
int ans[1000005];
bool used[1000005];

void update(int p){
	if(!p)
		return;
	children[p]=children[p*2]+children[p*2+1];
	update(p/2);
}

void Set(int p, int mark){
	if(pos[mark]){
		children[pos[mark]]=0;
		update(pos[mark]/2);
	}
	tree[p]=mark;
	pos[mark]=p;
	children[p]=1;
	update(p/2);
}

int Find(int p, int node){
	if(node >= (1<<21))
		return node;
	if(p < children[node*2])
		return Find(p, node*2);
	return Find(p-children[node*2], node*2+1);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	offset=(1<<21)+m;
	for(int i=0; i < n; ++i){
		Set(offset+i, i);
		ans[i]=-1;
		used[i]=0;
	}
	for(int i=0; i < m; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		--x;--y;
		int curPos = Find(y, 1);
		int curValue = ans[tree[curPos]];
		if(curValue != -1 && curValue != x){
			puts("-1");
			return 0;
		}
		ans[tree[curPos]]=x;
		Set(offset-i-1, tree[curPos]);
	}
	for(int i=0; i < n; ++i){
		if(ans[i] == -1)
			continue;
		if(used[ans[i]]){
			puts("-1");
			return 0;
		}
		used[ans[i]]=1;
	}
	int j=0;
	for(int i=0; i < n; ++i){
		if(ans[i] != -1)
			continue;
		while(used[j])
			++j;
		ans[i]=j;
		++j;
	}
	for(int i=0; i < n; ++i)
		printf("%d ", ans[i]+1);
	printf("\n");
	return 0;
}