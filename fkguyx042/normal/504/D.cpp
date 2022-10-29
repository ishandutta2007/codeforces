#include<stdio.h>
#include<bitset>
#include<cstring>
#define N 2016
using namespace std;
bitset<2016>base[N],be[N],now,get,space;
int ch[N],vis[N];char s[N];
int a[N],ok,m,last,k,i,T,len;
void Insert(int id){
    for (int i=k;i>=0;i--){
        if (!now[i]) continue;
        if (!vis[i]) {
            vis[i]=id;base[i]=now;ok=1;
            be[i]=get;be[i][i]=1;return;
        }now^=base[i];get^=be[i];
    }
}
int main(){
    scanf("%d",&m);
    for (T=1;T<=m;T++){
        scanf("%s",s+1);*a=strlen(s+1);
        for (i=1;i<=*a;i++) 
            a[i]=s[(*a)-i+1]-'0';
        get=now=space;k=-1;
        while (*a){
            now[++k]=a[1]&1;last=0;
            for (i=*a;i;i--)
                a[i]=last*10+a[i],last=a[i]&1,a[i]>>=1;
            if (!a[*a]) --*a;
      }ok=0;len=max(len,k);Insert(T);
      if (ok) {puts("0");continue;}
      for (*ch=0,i=len;i>=0;i--)
        if (get[i]) ch[++*ch]=vis[i];
      printf("%d",*ch);
      for (i=1;i<=*ch;i++)
        printf(" %d",ch[i]-1);
      puts("");
  }
}