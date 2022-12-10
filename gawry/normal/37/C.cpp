#include<cstdio>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int n,a[1010],b[1010];
string r[1010];
typedef pair<int,int> p2;
set<p2> left;
void calc(){
  if(left.empty())return;
  int first=left.begin()->second;
  left.erase(left.begin());
  if(left.empty()||-left.begin()->first!=a[first]){
    if(--a[first])left.insert(p2(-a[first],first));
    calc();
    r[first]+='0';
  }else{
    int second=left.begin()->second;
    left.erase(left.begin());
    if(--a[first])left.insert(p2(-a[first],first));
    calc();
    r[second]=r[first]+'1';
    r[first]+='0';
  }
  
}
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    int pos=a[i];
    while(pos>=0&&b[pos])b[pos]=0,pos--;
    if(pos<0){puts("NO");return 0;}
    b[pos]=1;
  }
  for(int i=1;i<1010;i++)if(b[0]&&b[i]){puts("NO");return 0;}
//  for(int i=0;i<10;i++)printf("%d",b[i]);puts("");
  puts("YES");
  typedef pair<int,int> p2;
  for(int i=0;i<n;i++)left.insert(p2(-a[i],i));
  calc();
  for(int i=0;i<n;i++)puts(r[i].c_str()); 
}