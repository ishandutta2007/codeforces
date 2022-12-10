#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
int n,m,l[501][501],r[501][501];
char a[501][501];
struct my_bitset {
  unsigned char data[64];
  my_bitset(){memset(data,0,sizeof(data));}
  void reset(){memset(data,0,sizeof(data));}
  my_bitset operator&(const my_bitset &x){
    my_bitset r;
    for(int i=0;i<64;i++)r.data[i]=data[i]&x.data[i];
    return r;
  }
  bool any(){
    for(int i=0;i<64;i++)if(data[i])return 1;
    return 0;
  }
  void set(int pos){
    data[pos>>3]|=1<<(pos&7);
  }
  bool test(int pos){
    return !!(data[pos>>3]&(1<<(pos&7)));
  }
  my_bitset &operator&=(const my_bitset &x){
    for(int i=0;i<64;i++)data[i]&=x.data[i];
    return *this;
  }
} a2[501];
unsigned char pre_r[256][256][2],pre_l[256][256][2];
void pre(){
  for(int old=0;old<256;old++)for(int board=0;board<256;board++)for(int prev=0;prev<=1;prev++){
    unsigned char &tmp=pre_r[old][board][prev];
    bool path=prev;
    for(int i=0;i<8;i++){
      path|=!!(old&1<<i);
      path&=!!(board&1<<i);
      if(path)tmp|=1<<i;
    }
  }
  for(int old=0;old<256;old++)for(int board=0;board<256;board++)for(int next=0;next<=1;next++){
    unsigned char &tmp=pre_l[old][board][next];
    bool path=next;
    for(int i=7;i>=0;i--){
      path|=!!(old&1<<i);
      path&=!!(board&1<<i);
      if(path)tmp|=1<<i;
    }
  }
}
long long mask;
struct data {
  data *left,*right;
  struct tab {
    long long t[64][64];
    tab(){memset(t,0,sizeof(t));}
//    my_bitset t[501];
  };
  tab *t[501];
  int from,to,middle;
  data(int _from,int _to):from(_from),to(_to){
    if(from+1>=to)return;
    middle=(from+to)/2;
 //   if(from+32>=to)return;
    left=new data(from,middle-1);
    right=new data(middle+1,to);
    for(int i=from;i<=to;i++)t[i]=new tab();
    my_bitset c;
//    printf("%d %d %d\n",from,to,middle);
    for(int i=0;i<m;i++){
      int shift=i%8*8;
      c.reset();
      c.set(i);
      for(int j=middle;j<=to;j++){
        c&=a2[j];
        for(int k=0;k<64;k++){
          bool prev=k?c.test(8*k-1):0;
          c.data[k]=pre_r[c.data[k]][a2[j].data[k]][prev];
          t[j]->t[k][i>>3]|=(long long)c.data[k]<<shift;
        }
      //  if(j%4==0){for(int k=0;k<m;k++)if(c.test(k))t[j]->t[k].set(i);}else for(int k=0;k<m;k+=4)if(c.test(k))t[j]->t[k].set(i);
      }
      c.reset();
      c.set(i);
      for(int j=middle;j>=from;j--){
        c&=a2[j];
        for(int k=63;k>=0;k--){
          bool next=k+1<64?c.test(8*(k+1)):0;
          c.data[k]=pre_l[c.data[k]][a2[j].data[k]][next];
          t[j]->t[k][i>>3]|=(long long)c.data[k]<<shift;
        }
      //  if(j%4==0){for(int k=0;k<m;k++)if(c.test(k))t[j]->t[k].set(i);}else for(int k=0;k<m;k+=4)if(c.test(k))t[j]->t[k].set(i);
      }
    }
  }
  bool ask(int x1,int y1,int x2,int y2){
    if(x1>x2){swap(x1,x2);swap(y1,y2);}
    if(x1+1>=x2)return r[x1][y1]>=l[x2][y2];
    if(x1<middle&&x2<middle)return left->ask(x1,y1,x2,y2);
    if(x1>middle&&x2>middle)return right->ask(x1,y1,x2,y2);
    if(x1==middle)return !!(t[x2]->t[y2>>3][y1>>3]&(1LL<<(y1%8*8+y2%8)));
    if(x2==middle)return !!(t[x1]->t[y1>>3][y2>>3]&(1LL<<(y2%8*8+y1%8)));
    for(int k=0;k<64;k++){
      long long x,y;
      x=t[x1]->t[y1>>3][k]>>(y1%8);
      y=t[x2]->t[y2>>3][k]>>(y2%8);
      if(x&y&mask)return 1;
    }
    return 0;
//    return (t[x1]->t[y1]&t[x2]->t[y2]).any();
  }
};
main(){
  mask=0;
  for(int i=0;i<8;i++)mask|=1LL<<(8*i);
  pre();
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)scanf(" %s",a[i]);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)l[i][j]=a[i][j]=='.'?(j&&a[i][j-1]=='.'?l[i][j-1]:j):1000;
    for(int j=m-1;j>=0;j--)r[i][j]=a[i][j]=='.'?(j+1<m&&a[i][j+1]=='.'?r[i][j+1]:j):-1000;
  }
  for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]=='.')a2[i].set(j);
  data r(0,n-1);
//  return 0;
  int q;
  scanf("%d",&q);
  while(q--){
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    --x1;--y1;--x2;--y2;
    printf("%s\n",r.ask(x1,y1,x2,y2)?"Yes":"No");
  }
}