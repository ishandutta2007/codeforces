#include<cstdio>
#include<vector>
using namespace std;
const int MAX=1000000+7;
char buf[MAX];
vector<int> a,b;
main(){
  scanf(" %s",buf);
  for(int i=0;buf[i];i++){
    if(buf[i]=='r')a.push_back(i+1);
    else b.push_back(i+1);
  }
  for(int i=0;i<a.size();i++)printf("%d\n",a[i]);
  for(int i=0;i<b.size();i++)printf("%d\n",b[b.size()-1-i]);
}