#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,m,x,a[N+9];
struct state{
  int x,v;
  state(int X=0,int V=0){x=X;v=V;}
  bool operator > (const state &p)const{return v>p.v;}
};

void into(){
  scanf("%d%d%d",&n,&m,&x);
  priority_queue<state,vector<state>,greater<state> >q;
  for (int i=1;i<=m;++i) q.push(state(i,0));
  puts("YES");
  for (int i=1;i<=n;++i){
	scanf("%d",&a[i]);
	state t=q.top();q.pop();
	//printf("%d %d\n",t.x,t.v);
	printf("%d ",t.x);
	t.v+=a[i];
	q.push(t);
  }
  puts("");
}

void work(){
}

void outo(){
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}