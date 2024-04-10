#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n;
vector<int> al[100005];
int h[100005];
int _h[100005];
int deg[100005];
bool visited[100005];
queue<int> q;
void dfs(int i){
	bool leaf=true;
	for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
		if (h[*it]==-1){
			leaf=false;
			h[*it]=h[i]+1;
			dfs(*it);
		}
	}
}
bool _dfs(int i){
	if (deg[_h[i]]==-1) deg[_h[i]]=al[i].size();
	else if (deg[_h[i]]!=al[i].size()) return false;
	for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
		if (_h[*it]==-1){
			_h[*it]=_h[i]+1;
			if (!_dfs(*it)) return false;
		}
	}
	return true;
}
void _try(int i){
	memset(deg,-1,sizeof(deg));
	memset(_h,-1,sizeof(_h));
	_h[i]=0;
	if (_dfs(i)){
		printf("%d\n",i);
		exit(0);
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	int a,b;
	for (int x=1;x<n;x++){
		scanf("%d%d",&a,&b);
		al[a].push_back(b);
		al[b].push_back(a);
	}
	memset(h,-1,sizeof(h));
	h[1]=0;
	dfs(1);
	int d1=0;
	for (int x=1;x<=n;x++){
		if (h[x]>h[d1]) d1=x;
	}
	memset(h,-1,sizeof(h));
	h[d1]=0;
	dfs(d1);
	int d2=0;
	for (int x=1;x<=n;x++){
		if (h[x]>h[d2]) d2=x;
	}
	_try(d1);
	_try(d2);
	if (h[d2]&1){
		printf("-1\n");
		return 0;
	}
	int k=h[d2]>>1;
	int node=d2;
	while (k--){
		for (vector<int>::iterator it=al[node].begin();it!=al[node].end();it++){
			if (h[*it]==h[node]-1){
				node=*it;
				break;
			}
		}
	}
	_try(node);
    visited[node]=true;
    q.push(node);
    while (!q.empty()){
        node=q.front(),q.pop();
        for (vector<int>::iterator it=al[node].begin();it!=al[node].end();it++){
            if (!visited[*it]){
                visited[*it]=true;
                if (al[*it].size()==1){
                    _try(*it);
                    printf("-1\n");
                    return 0;
                }
                if (al[*it].size()==2) q.push(*it);
            }
        }
    }
    printf("-1\n");
}