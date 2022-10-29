#include<cstdio>
#include<cstring>
using namespace std;
int f[11];
int i,j,m,n,p,k;
int flag;
char c[11];
int s[1001];
void ss(int left,int right,int num)
   { int i;
     if (flag) return;  
      if (num==m+1) {printf("YES\n"); for (i=1;i<=m-1;i++) {printf("%d ",s[i]);} printf("%d\n",s[m]); flag=1;return;}
      if (num&1)
        { for (i=1;i<=f[0];i++)
          if (f[i]!=s[num-1])
            if (left+f[i]>right) if (!flag) { s[num]=f[i]; ss(left+f[i],right,num+1); }
            }
        else { for (i=1;i<=f[0];i++)
           if (f[i]!=s[num-1])
           if (right+f[i]>left)  if (!flag) {s[num]=f[i];ss(left,right+f[i],num+1); }
           }
}         
int main()
 { scanf("%s",&c);
 scanf("%d",&m);
 flag=0;
 memset(f,0,sizeof(f));
  for (i=0;i<=9;i++)
    if (c[i]=='1')
       f[++f[0]]=i+1;  
 ss(0,0,1);
 if (!flag)
  printf("NO\n");
  return 0;
}