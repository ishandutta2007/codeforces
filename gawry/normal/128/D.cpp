#include<cstdio>
#include<map>
using namespace std;
int n,a;
map<int,int> cnt;
main(){
  scanf(" %d",&n);
  for(int i=0;i<n;i++)scanf(" %d",&a),++cnt[a];
  int cur=cnt.begin()->first+1;
  int opened=cnt.begin()->second;
  int taken=opened;
  while(opened){
    if(cnt[cur]<opened){
      puts("NO");
      return 0;
    }
    taken+=cnt[cur];
    opened=cnt[cur]-opened;
    ++cur;
  }
  puts(taken==n?"YES":"NO");
}