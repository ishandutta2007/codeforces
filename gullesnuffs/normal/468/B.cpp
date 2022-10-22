#include <bits/stdc++.h>

using namespace std;

int deg[100005];
int n, a, b;
int p[100005];
set<int> S;
map<int, int> M;
bool ok=1;
queue<int> q;
bool bel[100005];

void fix(int x){
	int y=M[x];
	--deg[y];
	if(deg[y] <= 1)
		q.push(y);
}

int main(){
	scanf("%d%d%d", &n, &a, &b);
	for(int i=0; i < n; ++i){
		scanf("%d", p+i);
		S.insert(p[i]);
		M[p[i]]=i;
	}
	for(int i=0; i < n; ++i){
		if(S.find(a-p[i]) != S.end())
			++deg[i];
		if(S.find(b-p[i]) != S.end())
			++deg[i];
		if(a == p[i]*2 || b == p[i]*2)
			deg[i]=1000000;
		if(deg[i] == 1)
			q.push(i);
		if(!deg[i])
			ok=0;

	}
	int i=0;
	int mode=0;
	while(ok && mode <= 1){
		if(q.empty()){
			for(; i < n; ++i){
					if(mode || deg[i] < 10)
						q.push(i);
					break;
			}
			++i;
			if(i >= n){
				i=0;
				++mode;
			}
		}
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			if(S.find(p[cur]) == S.end())
				continue;
			int other;
			int type=-1;
			if(S.find(a-p[cur]) != S.end()){
				other=M[a-p[cur]];
				type=0;
			}
			else if(S.find(b-p[cur]) != S.end()){
				other=M[b-p[cur]];
				type=1;
			}
			else
				ok=0;
			if(!ok)
				break;
			if(S.find(a-p[other]) != S.end())
				fix(a-p[other]);
			if(S.find(b-p[other]) != S.end())
				fix(b-p[other]);
			if(S.find(a-p[cur]) != S.end())
				fix(a-p[cur]);
			if(S.find(b-p[cur]) != S.end())
				fix(b-p[cur]);
			S.erase(p[cur]);
			S.erase(p[other]);
			bel[cur]=type;
			bel[other]=type;
		}
	}
	if(!ok)
		puts("NO");
	else{
		puts("YES");
		for(int j=0; j < n; ++j){
			printf("%d", bel[j]);
			if(j < n-1)
				printf(" ");
		}
		printf("\n");
	}
}