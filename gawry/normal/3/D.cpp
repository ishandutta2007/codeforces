#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
char t[100000];
int a[100000],b[100000],next,sum;
long long cost;
typedef pair<int,int> p2;
set<p2> s;
main(){
  scanf(" %s",t);  
  for(int i=0;t[i];i++){
    if(t[i]=='(')sum++;else if(t[i]==')')sum--;else{t[i]=')';sum--;scanf("%d %d",&a[next],&b[next]);cost+=b[next];s.insert(p2(a[next]-b[next],i));next++;}
//printf("%d: %d\n",i,sum);
    while(sum<0){
      if(s.empty()){puts("-1");return 0;}
      p2 first=*s.begin();
      s.erase(s.begin());
//      printf("%d %d\n",first.first,first.second);
      cost+=first.first;
      t[first.second]='(';
      sum+=2;
    }
  }
  if(sum)puts("-1");else cout<<cost<<endl<<t<<endl;
}