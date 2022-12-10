#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
const int MAX=1000000+123;
int n,t,p[MAX];
bool end[MAX];
main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&p[i]);
  scanf("%d",&t);
  while(t--){
    int x;
    scanf("%d",&x);
    end[x]=true;
  }
  vector<int> stack;
  for(int i=n;i>=1;i--)if(end[i]){
    p[i]=-p[i];
    stack.push_back(i);
  }else if(!stack.empty()&&p[stack.back()]==-p[i]){
    stack.pop_back();
  }else{
    if(end[i]){
      puts("NO");
      return 1;
    }
    p[i]=-p[i];
    stack.push_back(i);
  }
  if(!stack.empty()){
    puts("NO");
    return 0;
  }
  puts("YES");
  for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
}