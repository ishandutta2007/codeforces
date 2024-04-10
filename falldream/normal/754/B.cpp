#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
char s[50][50];
bool flag=false;
const int dis[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
int num1,num2,num3;
void renew(char x)
{
    if(x=='o') num2++;
    else if(x=='x') num1++;
    else num3++;
}

int main()
{
    for(int i=1;i<=4;i++)
        scanf("%s",s[i]+1);
    int num=0;char to;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            if(s[i][j]!='.') num++;
    to=(num&1)?'o':'x';
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            for(int k=0;k<8;k++)
            {
                num1=0,num2=0,num3=0;
                renew(s[i][j]);
                int xx=i+2*dis[k][0];
                int yy=j+2*dis[k][1];
                if(xx<1||yy<1||xx>4||yy>4) continue;
                int x2=i+dis[k][0];
                int x3=j+dis[k][1];
                renew(s[xx][yy]);renew(s[x2][x3]);
                if(num3==1&&((to=='o'&&num2==2)||(to=='x'&&num1==2))) flag=true;
            }
        }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}