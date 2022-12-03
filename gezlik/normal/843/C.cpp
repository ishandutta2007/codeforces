#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n;
struct side{
  int y,next,v;
}e[N*2+9];
int lin[N+9],cs;

void Ins(int x,int y){e[++cs].y=y;e[cs].next=lin[x];lin[x]=cs;}
void Ins2(int x,int y){Ins(x,y);Ins(y,x);}

void into(){
  scanf("%d",&n);
  for (int i=1;i<n;++i){
	int x,y;
	scanf("%d%d",&x,&y);
	Ins2(x,y);
  }
}

int siz[N+9];

void Dfs_siz(int k,int fa){
  siz[k]=1;
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fa){
	  Dfs_siz(e[i].y,k);
	  siz[k]+=siz[e[i].y];
	}
}

vector<int>ht;

void Dfs_heart(int k,int fa,int rot){
  int flag=1;
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fa){
	  Dfs_heart(e[i].y,k,rot);
	  if (siz[e[i].y]>n>>1) flag=0;
	}
  if (flag&&n-siz[k]<=n>>1) ht.push_back(k);
}

void Get_heart(){
  ht.clear();
  Dfs_siz(1,0);
  Dfs_heart(1,0,1);
}

struct answer{
  int x,y,z;
  answer(int X=0,int Y=0,int Z=0){x=X;y=Y;z=Z;}
};
vector<answer>ans;

vector<int>d;
int fa[N+9];

void Dfs_d(int k,int fat){
  d.push_back(k);
  fa[k]=fat;
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fat) Dfs_d(e[i].y,k);
}

void Get_ans(int rot,int x){
  d.clear();
  Dfs_d(x,rot);
  int last=x;
  for (int y:d){
	if (y==x) continue;
	ans.emplace_back(rot,last,y);
	ans.emplace_back(y,fa[y],x);
	last=y;
  }
  ans.emplace_back(rot,last,x);
}

int tag[N+9];

void Get_ans(int k){
  vector<int>son;
  for (int i=lin[k];i;i=e[i].next)
	if (!tag[e[i].y]) Get_ans(k,e[i].y);
}

void Get_ans(){
  Get_heart();
  for (int x:ht) tag[x]=1;
  for (int x:ht) Get_ans(x);
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d\n",ans.size());
  for (auto [x,y,z]:ans) printf("%d %d %d\n",x,y,z);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}