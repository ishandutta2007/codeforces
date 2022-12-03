#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1000;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

void work(){
}

stack<vector<int> >sta;

void outo(){
  for (;!sta.empty();sta.pop());
  sta.push(vector<int>(1,1));
  printf("%d\n",1);
  for (int i=2;i<=n;++i){
    if (a[i]==1){
	  sta.push(sta.top());
	  sta.top().push_back(1);
	}else{
	  for (;sta.top().back()^a[i]-1;sta.pop());
	  vector<int>t=sta.top();
	  sta.pop();
	  ++t.back();
	  sta.push(t);
	}
	printf("%d",sta.top()[0]);
	for (int vs=sta.top().size(),i=1;i<vs;++i)
	  printf(".%d",sta.top()[i]);
    puts("");
  }
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