#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int y1,m1,d1,y2,m2,d2,mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool rn(int y)
{
     return((y%400==0)||(y%4==0&&y%100!=0));
}
int day(int y,int m,int d)
{
    int ans=0;
    for(int i=1900;i<y;i++)ans+=365+rn(i);
    for(int i=1;i<m;i++)ans+=mo[i]+(i==2&&rn(y));
    return ans+d;
}
int main()
{
    scanf("%d:%d:%d",&y1,&m1,&d1);
    scanf("%d:%d:%d",&y2,&m2,&d2);
    cout<<abs(day(y1,m1,d1)-day(y2,m2,d2));
    return 0;
}