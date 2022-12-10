#include<cstdio>
#include<set>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;
const int MAX=100000;
int n,x[MAX],y[MAX],ans;
template<typename T> T forward(const T &t){
  T tmp=t;
  ++tmp;
  return tmp;
}
struct Xcmp {
  bool operator()(int a,int b){
    return x[a]<x[b]||x[a]==x[b]&&a<b;
  }
};
struct Ycmp {
  bool operator()(int a,int b){
    return y[a]<y[b]||y[a]==y[b]&&a<b;
  }
};
void solve(set<int,Xcmp> &sx,set<int,Ycmp> &sy){
  assert(sx.size()==sy.size());
 /* cout<<sx.size()<<" "<<sy.size()<<endl;
  assert(sx.size()==sy.size());
  printf("n=%d\n",sx.size());
  for(set<int,Xcmp>::iterator it=sx.begin();it!=sx.end();it++)cout<<*it<<","<<x[*it]<<endl;
  cout<<endl;
  for(set<int,Ycmp>::iterator it=sy.begin();it!=sy.end();it++)cout<<*it<<","<<y[*it]<<endl;
  cout<<endl;*/

//cout<<sx.size()<<endl;
  
  int n=sx.size();
  if(n==1){
    ++ans;
    return;
  }
  if(n==2){
    ++ans;
    ans+=x[*sx.begin()]+1<x[*sx.rbegin()]||y[*sy.begin()]+1<y[*sy.rbegin()];
    return;
  }

  set<int,Xcmp>::iterator sx_forward=sx.begin();
  set<int,Ycmp>::iterator sy_forward=sy.begin();
  set<int,Xcmp>::reverse_iterator sx_backward=sx.rbegin();
  set<int,Ycmp>::reverse_iterator sy_backward=sy.rbegin();
  int cnt=1;
  while(cnt<n){
    if(x[*sx_forward]+1<x[*forward(sx_forward)]){
      set<int,Xcmp> sx2;
      set<int,Ycmp> sy2;
      for(set<int,Xcmp>::iterator it=sx.begin();it!=forward(sx_forward);it++){
        int tmp=*it;
        sy.erase(tmp);
        sy2.insert(tmp);
      }
      sx2.insert(sx.begin(),forward(sx_forward));
      sx.erase(sx.begin(),forward(sx_forward));
    //  cout<<cnt<<endl;
      solve(sx,sy);
      solve(sx2,sy2);
      return;
    }
    if(y[*sy_forward]+1<y[*forward(sy_forward)]){
      set<int,Xcmp> sx2;
      set<int,Ycmp> sy2;
      for(set<int,Ycmp>::iterator it=sy.begin();it!=forward(sy_forward);it++){
        int tmp=*it;
        sx.erase(tmp);
        sx2.insert(tmp);
      }
      sy2.insert(sy.begin(),forward(sy_forward));
      sy.erase(sy.begin(),forward(sy_forward));
   //   cout<<cnt<<endl;
      solve(sx,sy);
      solve(sx2,sy2);
      return;
    }
    if(x[*sx_backward]-1>x[*forward(sx_backward)]){
      set<int,Xcmp> sx2;
      set<int,Ycmp> sy2;
      for(set<int,Xcmp>::reverse_iterator it=sx.rbegin();it!=forward(sx_backward);it++){
        int tmp=*it;
        sy.erase(tmp);
        sy2.insert(tmp);
      }
      sx2.insert(sx.rbegin(),forward(sx_backward));
      sx.erase(--sx_backward.base(),sx.end());
    //  cout<<cnt<<endl;
      solve(sx,sy);
      solve(sx2,sy2);
      return;
    }
    if(y[*sy_backward]-1>y[*forward(sy_backward)]){
      set<int,Xcmp> sx2;
      set<int,Ycmp> sy2;
      for(set<int,Ycmp>::reverse_iterator it=sy.rbegin();it!=forward(sy_backward);it++){
        int tmp=*it;
        sx.erase(tmp);
        sx2.insert(tmp);
      }
      sy2.insert(sy.rbegin(),forward(sy_backward));
      sy.erase(--sy_backward.base(),sy.end());
      //cout<<cnt<<endl;
      solve(sx,sy);
      solve(sx2,sy2);
      return;
    }
    ++sx_forward;
    ++sy_forward;
    ++sx_backward;
    ++sy_backward;
    ++cnt;
  }
  ++ans;
}
int main(){
  scanf("%d",&n);
  set<int,Xcmp> sx;
  set<int,Ycmp> sy;
  for(int i=0;i<n;i++){
    scanf("%d %d",&x[i],&y[i]);
  //  x[i]=y[i]=2*i;
    sx.insert(i);
    sy.insert(i);
  }
  ans=0;
  solve(sx,sy);
  printf("%d\n",ans);
  return 0;
}