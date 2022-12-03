#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=300000;

int n,a[N+9],b[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
    scanf("%d",&a[i]);
  for (int i=1;i<=n;++i)
    scanf("%d",&b[i]);
}

int uni[N+9];

int Query_uni(int k){return k==uni[k]?k:uni[k]=Query_uni(uni[k]);}

int dis[N+9],pre[N+9][2];
queue<int>q;

void Get_ans(){
  for (int i=0;i<=n;++i) uni[i]=i;
  dis[n]=1;q.push(n);
  uni[n]=n-1;
  for (;!q.empty();){
    int k=q.front();q.pop();
    //printf("%d : %d %d %d\n",k,dis[k],pre[k][0],pre[k][1]);
    for (;2333;){
      int y=Query_uni(k);
      //printf("%d : %d\n",k,y);
      if (k-y>a[k]) break;
      int z=y+b[y];
      if (!dis[z]){
        dis[z]=dis[k]+1;
        pre[z][0]=y;
        pre[z][1]=k;
        q.push(z);
      }
      if (!y) break;
      uni[y]=y-1;
    }
  }
}

void work(){
  Get_ans();
}

void outo(){
  if (!dis[0]) puts("-1");
  else{
    printf("%d\n",dis[0]-1);
    vector<int>ans;
    for (int k=0;k!=n;k=pre[k][1]){
      int y=pre[k][0],z=pre[k][1];
      ans.push_back(y);
    }
    reverse(ans.begin(),ans.end());
    for (int x:ans)
      printf("%d ",x);
    puts("");
  }
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