#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
#define MAX 1010000
#define POWER (1<<21)
char s[MAX];
int incr[2*POWER],decr[2*POWER],zero[2*POWER],one[2*POWER],rev[2*POWER];
int get_incr(int x){
  return rev[x]?decr[x]:incr[x];
}
int get_decr(int x){
  return !rev[x]?decr[x]:incr[x];
}
int get_one(int x){
  return rev[x]?zero[x]:one[x];
}
int get_zero(int x){
  return !rev[x]?zero[x]:one[x];
}
void fix(int i){
  if(i<POWER){
    one[i]=get_one(2*i)+get_one(2*i+1);
    zero[i]=get_zero(2*i)+get_zero(2*i+1);
    incr[i]=max(get_incr(2*i)+get_one(2*i+1),get_zero(2*i)+get_incr(2*i+1));
    decr[i]=max(get_one(2*i)+get_decr(2*i+1),get_decr(2*i)+get_zero(2*i+1));
  }else{
    incr[i]=decr[i]=max(get_one(i),get_zero(i));
  }
}
void move(int x){
  if(!rev[x])return;
  if(x<POWER){
    rev[2*x]^=1;
    rev[2*x+1]^=1;
  }else{
    swap(one[x],zero[x]);
  }
  rev[x]=0;
  fix(x);
}
void move_path(int x){
  if(x>1)move_path(x/2);
  move(x);
}
void flip(int from,int to){
  from+=POWER;
  to+=POWER;
  move(from);
  move(to);
  rev[from]^=1;
  if(from<to)rev[to]^=1;
  while(from+1<to){
    if(from%2==0){
      rev[from+1]^=1;
    }
    if(to%2){
      rev[to-1]^=1;
    }
    fix(from);
    fix(to);
    from/=2;
    to/=2;
  }
  int tmp=from;
  while(from){
    fix(from);
    from/=2;
  }
  while(to){
    fix(to);
    to/=2;
  }
}
main(){
  scanf("%d %d %s",&n,&m,s);
  for(int i=0;i<n;i++){
    if(s[i]=='4')++zero[POWER+i];else ++one[POWER+i];
    incr[POWER+i]=decr[POWER+i]=max(zero[POWER+i],one[POWER+i]);
  }
  for(int i=POWER-1;i;i--)fix(i);
  while(m--){
    char buf[20];
    scanf(" %s",buf);
    if(buf[0]=='c')printf("%d\n",get_incr(1));
    else{
      int from,to;
      scanf("%d %d",&from,&to);
      flip(from-1,to-1);
    }
  }
}