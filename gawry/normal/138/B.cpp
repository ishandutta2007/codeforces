#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
#define MAX 110000
char a[MAX],b[MAX],aa[MAX],bb[MAX];
int cnt_a[11],cnt_b[11],best;
main(){
  scanf(" %s",a);
  strcpy(b,a);
  for(int i=0;a[i];i++)++cnt_a[a[i]-'0'];
  for(int i=0;b[i];i++)++cnt_b[b[i]-'0'];
  strcpy(aa,a);
  strcpy(bb,b);
  int n=strlen(a);
  sort(aa,aa+n);
  sort(bb,bb+n);
  reverse(aa,aa+n);
  reverse(bb,bb+n);
  best=cnt_a[0];
  for(int last=1;last<10;last++)if(cnt_a[last]&&cnt_b[10-last]){
    --cnt_a[last];
    --cnt_b[10-last];
    int cur=1;
    for(int i=0;i<10;i++)cur+=min(cnt_a[i],cnt_b[9-i]);
    int zero_a=cnt_a[0]-min(cnt_a[0],cnt_b[9]);
    int zero_b=cnt_b[0]-min(cnt_a[9],cnt_b[0]);
    int zero=min(zero_a,zero_b);
    cnt_a[0]-=zero;
    cnt_b[0]-=zero;
    if(cur>best){
      int next=0,next2=0;
      for(int i=0;i<zero;i++)aa[next++]='0',bb[next2++]='0';
      aa[next++]='0'+last;
      bb[next2++]='0'+10-last;
      for(int i=0;i<10;i++)for(int j=0;j<min(cnt_a[i],cnt_b[9-i]);j++)aa[next++]='0'+i,bb[next2++]='0'+9-i;
      for(int i=0;i<10;i++)for(int j=min(cnt_a[i],cnt_b[9-i]);j<cnt_a[i];j++)aa[next++]='0'+i;
      for(int i=0;i<10;i++)for(int j=min(cnt_a[i],cnt_b[9-i]);j<cnt_b[9-i];j++)bb[next2++]='0'+9-i;
      reverse(aa,aa+next);
      reverse(bb,bb+next2);
      best=cur;
    }
    cnt_a[0]+=zero;
    cnt_b[0]+=zero;
    ++cnt_a[last];
    ++cnt_b[10-last];
  }
  puts(aa);
  puts(bb);
}