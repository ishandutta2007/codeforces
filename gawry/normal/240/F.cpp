#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
#define MAX 110000
#define POWER (1<<17)
char buf[MAX];
int len[2*POWER];
typedef pair<int,int> p2;
struct tree {
  int sum[2*POWER];
  char deferred[2*POWER];
  void f(p2 &x,int pos){
    if(deferred[pos]==1)x.first=x.second;
    if(deferred[pos]==-1)x.first=0;
  }
  void clear(int pos){
    if(pos){
      clear(pos/2);
      if(deferred[pos]){
        deferred[2*pos]=deferred[2*pos+1]=deferred[pos];
        if(deferred[pos]==1)sum[2*pos]=sum[2*pos+1]=len[2*pos];
        if(deferred[pos]==-1)sum[2*pos]=sum[2*pos+1]=0;
        deferred[pos]=0;
      }
    }
  }
  void defer(int pos,int val){
    sum[pos]=val?len[pos]:0;
    if(pos<POWER)deferred[pos]=val?1:-1;
  }
  void change(int from,int to,int val){
    from+=POWER;
    to+=POWER;
    clear(from/2);
    clear(to/2);
    sum[from]=sum[to]=val;
    while(from+1<to){
      if(from%2==0)defer(from+1,val);
      if(to%2)defer(to-1,val);
      if(from<POWER)sum[from]=sum[2*from]+sum[2*from+1];
      if(to<POWER)sum[to]=sum[2*to]+sum[2*to+1];
      from/=2;
      to/=2;
    }
    while(from){
      if(from<POWER)sum[from]=sum[2*from]+sum[2*from+1];
      from/=2;
    }
    while(to){
      if(to<POWER)sum[to]=sum[2*to]+sum[2*to+1];
      to/=2;
    }
  }
  int count(int from,int to){
    from+=POWER;
    to+=POWER;
    p2 total(0,0);
    if(from<to){
      p2 left(sum[from],1),right(sum[to],1);
      while(from+1<to){
        if(from%2==0)left.first+=sum[from+1],left.second+=len[from+1];
        if(to%2)right.first+=sum[to-1],right.second+=len[to-1];
        from/=2;
        to/=2;
        f(left,from);
        f(right,to);
      }
      while(from!=to){
        from/=2;
        to/=2;
        f(left,from);
        f(right,to);
      }
      total=p2(left.first+right.first,left.second+right.second);
    }else{
      total=p2(sum[from],1);
    }
    while(from>1){
      from/=2;
      f(total,from);
    }
    return total.first;
  }
} t[26];
main(){
  for(int i=POWER;i<2*POWER;i++)len[i]=1;
  for(int i=POWER-1;i;i--)len[i]=len[2*i]+len[2*i+1];
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d %d %s",&n,&m,buf);
  for(int i=0;i<n;i++)t[buf[i]-'a'].change(i,i,1);
  while(m--){
    int from,to;
    scanf("%d %d",&from,&to);
    --from;--to;
    int len=to-from+1,cnt[26];
    for(int i=0;i<26;i++)cnt[i]=t[i].count(from,to);
    int odd=0;
    for(int i=0;i<26;i++)odd+=cnt[i]%2;
    if(len%2==0&&odd||len%2&&odd!=1)continue;
    for(int i=0;i<26;i++)t[i].change(from,to,0);   
    if(odd==1)for(int i=0;i<26;i++)if(cnt[i]%2)t[i].change(from+len/2,from+len/2,1),--cnt[i];
    for(int i=0;i<26;i++){
      int tmp=cnt[i]/2;
      if(!tmp)continue;
      t[i].change(from,from+tmp-1,1);
      t[i].change(to-tmp+1,to,1);
      from+=tmp;
      to-=tmp;
    }
  }
  for(int i=0;i<n;i++)for(int j=0;j<26;j++)if(t[j].count(i,i)){buf[i]='a'+j;break;}
  puts(buf);
}