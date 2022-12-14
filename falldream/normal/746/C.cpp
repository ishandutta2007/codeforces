#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int s,ss1,ss2,tt1,tt2;
int pos,dir,way,ans;
int main()
{
    s=read();ss1=read();ss2=read();tt2=read();tt1=read();
    pos=read();dir=read();
    if(ss1<ss2) way=1;
    else way=-1;
    if(way==dir)
    {
        if(way==1&&ss1>=pos) ans=(ss2-pos)*tt2;
	if(way==-1&&ss1<=pos) ans=(pos-ss2)*tt2;
	if(way==1&&ss1<pos) ans=(2*s+ss2-pos)*tt2;
	if(way==-1&&ss1>pos) ans=(2*s+pos-ss2)*tt2;
    } 
    else
    {
	if(way==1) ans=(pos+ss2)*tt2;
	if(way==-1) ans=(2*s-pos-ss2)*tt2;
    }
    int dist=abs(ss2-ss1)*tt1;
    printf("%d",min(ans,dist));
    return 0;
}