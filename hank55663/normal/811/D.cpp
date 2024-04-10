#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 5005
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
char op[4]={'U','D','L','R'};
vector<char> ans;
vector<char> temp;
int visit[105][105];
int X[4]={-1,1,0,0};
int Y[4]={0,0,-1,1}; 
char c[105][105];
int n,m;
void dfs(int x,int y){
	if(c[x][y]=='F'){
		ans=temp;
		return ;
	}
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		if(x+X[i]>0&&x+X[i]<=n&&y+Y[i]>0&&y+Y[i]<=m&&c[x+X[i]][y+Y[i]]!='*'&&!visit[x+X[i]][y+Y[i]]){
			temp.pb(op[i]);
			dfs(x+X[i],y+Y[i]);
					temp.pop_back();
		}
	}
} 
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	int x=1,y=1;
	if(c[x][y]=='F')
			return 0; 
	int okud=0,oklr=0;
	if(c[x+1][y]!='*'){
		printf("%c\n",op[0]);
		fflush(stdout);
		scanf("%d %d",&x,&y);
		if(c[x][y]=='F')
			return 0; 
		if(x!=1){
			swap(op[0],op[1]);
			printf("%c\n",op[0]);
			fflush(stdout);
			scanf("%d %d",&x,&y);
			if(c[x][y]=='F')
			return 0; 
		}
		okud=1;
	}
	if(c[x][y+1]!='*'){
		printf("%c\n",op[2]);
		fflush(stdout);
		scanf("%d %d",&x,&y);
		if(c[x][y]=='F')
			return 0; 
		if(y!=1){
			swap(op[2],op[3]);
			printf("%c\n",op[2]);
			fflush(stdout);
			scanf("%d %d",&x,&y);
			if(c[x][y]=='F')
			return 0; 
		}
		oklr=1;
	}
	vector<char> v;
	if(!okud){
		while(c[x+1][y]=='*'){
			printf("%c\n",op[3]);
			v.pb(op[2]);
			fflush(stdout);
			scanf("%d %d",&x,&y);
			if(c[x][y]=='F')
			return 0; 
		}
		printf("%c\n",op[0]);
		fflush(stdout);
		scanf("%d %d",&x,&y);
		if(c[x][y]=='F')
			return 0; 
		if(x!=1){
			swap(op[0],op[1]);
			printf("%c\n",op[0]);
			fflush(stdout);
			scanf("%d %d",&x,&y);
			 
		}
		while(!v.empty()){
			printf("%c\n",v.back());
			v.pop_back();
			fflush(stdout);
			scanf("%d %d",&x,&y);
		}
	}
	if(!oklr){
		while(c[x][y+1]=='*'){
			printf("%c\n",op[1]);
			v.pb(op[0]);
			fflush(stdout);
			scanf("%d %d",&x,&y);
			if(c[x][y]=='F')
			return 0; 
		}
		printf("%c\n",op[2]);
		fflush(stdout);
		scanf("%d %d",&x,&y);
		if(c[x][y]=='F')
			return 0; 
		if(y!=1){
			swap(op[2],op[3]);
			printf("%c\n",op[2]);
			fflush(stdout);
			scanf("%d %d",&x,&y);
			 
		}
		while(!v.empty()){
			printf("%c\n",v.back());
			v.pop_back();
			fflush(stdout);
			scanf("%d %d",&x,&y);
		}
	}
	assert(x==1&&y==1);
	MEM(visit);
//	printf("?");
	dfs(x,y);
	for(vector<char>::iterator it=ans.begin();it!=ans.end();it++){
		printf("%c\n",*it);
		fflush(stdout);
		scanf("%d %d",&x,&y);
	}
    return 0;
}