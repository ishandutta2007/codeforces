#include<bits/stdc++.h>
#define N 200005
#define mk make_pair
using namespace std;
typedef pair<double,int> Pair;
const double EPS=1e-13;
set<Pair>Succ,Pre;double succ[N],pre[N],ans;
int p[N],q[N],c[N],n,t,Q,i,id,ch,opt;
double F(int id,int x){
  return p[id]*(x*1./(x+q[id]));
}
double calc(int id,int x){
  if (x>q[id]||!x) return 0;
  return F(id,x)-F(id,x-1);
}
void Del(int id){
  Pre.erase(mk(pre[id],id));
  Succ.erase(mk(succ[id],id));
}
void Ins(int id){
  Pre.insert(mk(pre[id]=c[id]?calc(id,c[id]):1e18,id));
  Succ.insert(mk(succ[id]=c[id]+1<=q[id]?calc(id,c[id]+1):-1e18,id));
}
void update(){
  while (ch<t){
    Pair top=*Succ.rbegin();
    if (top.first<=EPS) break;
    int id=top.second;
    ans+=top.first;
    Del(id);++c[id];
    Ins(id);ch++;
  }while (true){
    Pair top1=*Succ.rbegin();
    Pair top2=*Pre.begin();
    double get=top1.first-top2.first;
    if (get<=EPS) break;ans+=get;
    int id=top1.second;
    Del(id);++c[id];Ins(id);
    id=top2.second;
    Del(id);--c[id];Ins(id);
  }
}
void addnum(){
  //
  //ch
  // 
  Del(id);
  ans-=F(id,c[id]);q[id]++;
  if (c[id]) ans+=F(id,--c[id]),--ch;
  Ins(id);
}
int decnum(){
  //
  // 
  // 
  Del(id);
  ans-=F(id,c[id]);q[id]--;
  if (c[id]>q[id]) --c[id],--ch;
  ans+=F(id,c[id]);
  Ins(id);
}
int main(){
  scanf("%d%d%d",&n,&t,&Q);
  for (i=1;i<=n;i++)
    scanf("%d",&p[i]);
  for (i=1;i<=n;i++)
    scanf("%d",&q[i]),Ins(i);
  update();//printf("%.10f\n",ans);
  while (Q--){
    scanf("%d%d",&opt,&id);
    if (opt==1) addnum();else decnum();
    update();printf("%.10f\n",ans);
  }
}