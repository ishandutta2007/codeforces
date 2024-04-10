/*
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define move adsfasdfasd

#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long xp,yp,xv,yv;

long move;

bool canmove(long x,long y)
{
 if (x==xp&&y==yp)return false;
 if (x==xv&&y==yv)return false;
 if (x<0||y<0)return false;
 return true;
}

long get_score(long x,long y)
{
 if (!canmove(x,y))return 1e9;
 return abs(x-y-xv+yv);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>xp>>yp>>xv>>yv;

move=1;

while (true)
{
// cout<<xp<<" "<<yp<<" "<<xv<<" "<<yv<<endl;
 if (xv==0&&yv==0)
 {
  cout<<"Vasiliy"<<endl;
  break;
 }
 if (xp==0&&yp==0)
 {
  cout<<"Polycarp"<<endl;
  break;
 }
 
 move^=1;
 if (move==1)
 {
 if (canmove(xv-1,yv-1))
  {xv--,yv--;continue;}
 if (canmove(xv-1,yv))
  {xv--;continue;}
 if (canmove(xv,yv-1))
  {yv--;continue;}
  continue;
 }
 
 long val1=get_score(xp-1,yp);
 long val2=get_score(xp,yp-1);
 if (val1>1e7&&val2>1e7)continue;
 if (val1<val2)--xp;
 else --yp;
}

cin.get();cin.get();
return 0;}