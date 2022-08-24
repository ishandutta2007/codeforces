#include<bits/stdc++.h>
using namespace std;
int t,p;
string f[256][3];
char s[20];
inline void orz(string &a,string b)
{
    //cout<<a<<" "<<b<<"\n";
    if(b.size()<a.size() || b.size()==a.size() && b<a)
      {
       a=b;
       p=1;
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	for(i=0;i<256;i++)
	  for(j=0;j<3;j++)
	    for(k=1;k<=50;k++)
	      f[i][j]=f[i][j]+"x";
	//f[0][0]="";
	f[15][0]="x";
	f[51][0]="y";
	f[85][0]="z";
	p=1;
	while(p)
	  {
       p=0;
       for(i=0;i<256;i++)
         for(j=1;j<3;j++)
           orz(f[i][j],f[i][j-1]);
       for(i=0;i<256;i++)
         {
          orz(f[i][0],"!"+f[i^255][0]);
          orz(f[i][0],"!("+f[i^255][2]+")");
         }
       for(i=0;i<256;i++)
         for(j=0;j<256;j++)
           {
            orz(f[i&j][1],f[i][1]+"&"+f[j][0]);
            orz(f[i&j][1],f[i][1]+"&("+f[j][2]+")");
            orz(f[i&j][1],"("+f[i][2]+")&"+f[j][0]);
            orz(f[i&j][1],"("+f[i][2]+")&("+f[j][2]+")");
           }
       for(i=0;i<256;i++)
         for(j=0;j<256;j++)
           {
            orz(f[i|j][2],f[i][2]+"|"+f[j][1]);
            orz(f[i|j][2],f[i][2]+"|("+f[j][2]+")");
           }
      }
    scanf("%d",&t);
    while(t--)
      {
       scanf("%s",&s);
       for(i=1,j=0,k=0;j<8;j++)
         k=k*2+s[j]-'0';
       cout<<f[k][2]<<"\n";
      }
	return 0;
}