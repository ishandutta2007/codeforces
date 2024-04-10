#include<bits/stdc++.h>
using namespace std;
#define res int
#define pb push_back
const int N=100+10;
int read()
{
	static int sl,fh,ch;
	sl=0;fh=1;ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int n,m;
int main()
{
    res T=read();
    while(T--){
        n=read(),m=read();
        printf("SCAN 1 1\n"), fflush(stdout);
        res A=read();
        printf("SCAN 1 %d\n",m), fflush(stdout);
        res B=read();
        res X=(A+B+6-2*m)/2,Y=(A-B+2+2*m)/2;
        printf("SCAN %d 1\n",X/2), fflush(stdout);
        res x=read(),dX=x+2-Y;
        printf("SCAN 1 %d\n",Y/2), fflush(stdout);
        res y=read(),dY=y+2-X;
        res x0=(X+dX)/2,x1=(X-dX)/2;
        res y0=(Y+dY)/2,y1=(Y-dY)/2;
        printf("DIG %d %d\n",x0,y0), fflush(stdout);
        res op=read();
        if(!op){
            printf("DIG %d %d\n",x0,y1), fflush(stdout);
            read();
            printf("DIG %d %d\n",x1,y0), fflush(stdout);
            read();
        }
        else {
            printf("DIG %d %d\n",x1,y1), fflush(stdout);
            read();
        }
    }
	return 0;
}