#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char c[31];
int i,j,m,n,p,k;
char s1[100001];
char s;
int main()
{ scanf("%c",&s);
  c[0]='q';c[1]='w';c[2]='e';
  c[3]='r';c[4]='t';c[5]='y';
  c[6]='u';c[7]='i';c[8]='o';
  c[9]='p';c[10]='a';c[11]='s';
  c[12]='d';c[13]='f';c[14]='g';
  c[15]='h';c[16]='j';c[17]='k';
  c[18]='l';c[19]=';';c[20]='z';
  c[21]='x';c[22]='c';c[23]='v';
  c[24]='b';c[25]='n';c[26]='m';
  c[27]=',';c[28]='.';c[29]='/';
  scanf("%s",&s1);
  for (i=0;i<strlen(s1);i++)
    for (j=0;j<30;j++)
      if (c[j]==s1[i])
      printf("%c",c[j+((s=='R')?-1:1)]);
}