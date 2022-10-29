#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,X[101];
char c[10001];
int check(int x)
{     char Kth=c[x]+1;
    for (;Kth<=p+'a'-1&&(x>0&&Kth==c[x-1]||x>1&&Kth==c[x-2]);)
	Kth++;
    if (Kth>p+'a'-1) return false;
    c[x]=Kth;
    int i;
      for (i=x+1;i<n;i++)
      {   X[c[i-1]-'a']++;
         if (i>1) X[c[i-2]-'a']++;
         if (!X[0]) c[i]='a';
         else if (!X[1]) c[i]='b';
         else c[i]='c';
           X[c[i-1]-'a']--;
         if (i>1) X[c[i-2]-'a']--;
    }
printf("%s",c);
return true;
}
int main()
{scanf("%d%d",&n,&p);
  scanf("%s",&c);
  if (p==1) printf("NO\n");
  else if (p==2) {
  	 if(n==1) if(c[0]=='a') printf("b"); else printf("NO\n");
  	 if (n==2) 
  	  if (c[0]=='a'&&c[1]=='a') printf("ab\n");
  	  else if (c[0]=='a'&&c[1]=='b') printf("ba\n");
  	  else printf("NO\n");
  }
  else {
  	 for (i=n-1;i>=0;i--)
  	 if (check(i)) break;
  	 if (i<0) printf("NO\n");
  }
}