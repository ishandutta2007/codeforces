#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

string s,t;
int x[3],y[3];

void toint(string str, int i)
{
     int pos;
     pos = str.find("a");
     if(pos != -1) x[i]=1;
     
     pos = str.find("b");
     if(pos != -1) x[i]=2;
     
     pos = str.find("c");
     if(pos != -1) x[i]=3;
     
     pos = str.find("d");
     if(pos != -1) x[i]=4;
     
     pos = str.find("e");
     if(pos != -1) x[i]=5;
     
     pos = str.find("f");
     if(pos != -1) x[i]=6;
     
     pos = str.find("g");
     if(pos != -1) x[i]=7;
     
     pos = str.find("h");
     if(pos != -1) x[i]=8;
     
     pos = str.find("1");
     if(pos != -1) y[i]=1;
     
     pos = str.find("2");
     if(pos != -1) y[i]=2;
     
     pos = str.find("3");
     if(pos != -1) y[i]=3;
     
     pos = str.find("4");
     if(pos != -1) y[i]=4;
     
     pos = str.find("5");
     if(pos != -1) y[i]=5;
     
     pos = str.find("6");
     if(pos != -1) y[i]=6;
     
     pos = str.find("7");
     if(pos != -1) y[i]=7;
     
     pos = str.find("8");
     if(pos != -1) y[i]=8;
}

void move()
{
     while(x[1]!=x[2] || y[1]!=y[2])
     {
                      if(x[1]<x[2] && y[1]==y[2])
                      {
                                   x[1]++;
                                   puts("R");
                      }
                      if(x[1]>x[2] && y[1]==y[2])
                      {
                                   x[1]--;
                                   puts("L");
                      }
                      if(x[1]==x[2] && y[1]<y[2])
                      {
                                   y[1]++;
                                   puts("U");
                      }
                      if(x[1]==x[2] && y[1]>y[2])
                      {
                                   y[1]--;
                                   puts("D");
                      }
                      if(x[1]<x[2] && y[1]<y[2])
                      {
                                   x[1]++;
                                   y[1]++;
                                   puts("RU");
                      }
                      if(x[1]<x[2] && y[1]>y[2])
                      {
                                   x[1]++;
                                   y[1]--;
                                   puts("RD");
                      }
                      if(x[1]>x[2] && y[1]<y[2])
                      {
                                   x[1]--;
                                   y[1]++;
                                   puts("LU");
                      }
                      if(x[1]>x[2] && y[1]>y[2])
                      {
                                   x[1]--;
                                   y[1]--;
                                   puts("LD");
                      }
     }
}

int main()
{
    cin >> s >> t;
    toint(s,1);
    toint(t,2);
    printf("%d\n",max(abs(x[1]-x[2]),abs(y[1]-y[2])));
    move();
    return 0;
}