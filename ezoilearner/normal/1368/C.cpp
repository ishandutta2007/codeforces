#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define Maxn 500010
struct Point{
	int x,y;
	Point(){x=y=0;}
	Point(int _x,int _y){x=_x;y=_y;}
}point[Maxn];
int cnt=0;

int main(){
   int n;
   scanf("%d",&n);
   n--;
   point[++cnt]=Point(0,2);
   point[++cnt]=Point(0,1);
   point[++cnt]=Point(1,1);
   point[++cnt]=Point(1,2);
   point[++cnt]=Point(1,0);
   point[++cnt]=Point(2,0);
   point[++cnt]=Point(2,1);
   int x=2,y=0;
   for(int i=1;i<=n;++i){
   	    point[++cnt]=Point(x,y-1);
   	    point[++cnt]=Point(x+1,y);
   	    point[++cnt]=Point(x+1,y-1);
   	    x++;y--;
   }
   printf("%d\n",cnt); 
   for(int i=1;i<=cnt;++i)printf("%d %d\n",point[i].x,point[i].y);
   return 0;
}