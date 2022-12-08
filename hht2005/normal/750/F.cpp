#include<bits/stdc++.h>
using namespace std;
#define chk1 if(FL)continue
#define chk2 if(FL)return -1
#define chk3 if(FL)break
const int N=1e5+10;
vector<int>S[N];
int FL,deg[N],dep;
void Q(int x) {
	if(!S[x].empty())return;
	printf("? %d\n",x);fflush(stdout);
	int a;
	scanf("%d",deg+x);
	for(int i=1;i<=deg[x];i++) {
		scanf("%d",&a);
		S[x].push_back(a);
	}
	if(deg[x]==2) {
		printf("! %d\n",x);fflush(stdout);
		FL=1;
	}
}
int bfs(vector<int>X,vector<int>Fa) {
	if(int(X.size())>2)dep--;
	int f[3]={0,0,0},F=0;
	for(int i=0;i<int(X.size());i++) {
		int x=X[i];
		Q(x);chk2;
		if(deg[x]==1)
			f[i]=F=1;
	}
	vector<int>Y;
	for(int i=0;i<3&&F;i++)
		if(!f[i])return i;
	for(int i=0;i<int(X.size());i++) {
		int x=X[i],fa=Fa[i],to=0;
		for(int y:S[x])
			if(y!=fa&&(to==0||deg[y]))
				to=y;
		Y.push_back(to);
	}
	return bfs(Y,X);
}
int main() {
	int T,h;
	scanf("%d",&T);
	while(T--) {
		FL=0;
		scanf("%d",&h);
		for(int i=1;i<1<<h;i++)
			S[i].clear(),deg[i]=0;
		Q(1);chk1;
		int p=1,fa=1;
		dep=h;
		if(deg[1]==3) {
			int t=bfs(S[1],{1,1,1});
			chk1;
			p=S[1][t];
		} else p=S[1][0];
		Q(p);chk1;
		dep--;
		vector<int>X,t;
		while(h<5||dep>3) {
			X.clear();
			for(int y:S[p])
				if(y!=fa)X.push_back(y);
			int t=bfs(X,{p,p});
			chk3;
			fa=p;
			p=X[t];
			dep--;
			Q(p);chk3;
		}
		chk1;
		X.clear();
		t.clear();
		for(int y:S[p])
			if(y!=fa) {
				Q(y);chk3;
				for(int z:S[y])
					if(z!=p)X.push_back(z);
			}
		chk1;
		for(int i=3;i>=0;i--) {
			if(deg[X[i]])continue;
			t.push_back(X[i]);
		}
		for(int i=0;i<int(t.size()-1);i++) {
			Q(t[i]);chk3;
		}
		chk1;
		printf("! %d\n",t.back());fflush(stdout);
	}
	return 0;
}