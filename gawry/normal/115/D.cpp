#include<cstdio>
#include<cstring>
#include<cassert>
#include<cctype>
char t[2010];
#define MOD (1000000+3)
int n,m[2010][2010],a[2010][2010];
main(){
  gets(t);
  t[strlen(t)]='$';
  n=strlen(t);
  m[0][0]=1;
  for(int start=0;start<n;start++){
    int s=0;
    for(int open=0;open<n;open++){
      s+=a[start][open];
      if(s>=MOD)s-=MOD;
      m[start][open]+=s;
      if(m[start][open]>=MOD)m[start][open]-=MOD;
      if(!m[start][open])continue;
    int next=start;
    if(t[next]=='+'||t[start]=='-'){
      ++next;
      m[next][open+1]=(m[next][open+1]+m[start][open])%MOD;
    }else{
      if(!isdigit(t[next]))continue;
      while(isdigit(t[next]))next++;
      assert(!isdigit(t[next]));
      ++next;
      a[next][1]=(a[next][1]+m[start][open])%MOD;
      a[next][open+2]=(a[next][open+2]+MOD-m[start][open])%MOD;
    }}
  }
  printf("%d\n",(m[n][1]+a[n][1])%MOD);
}