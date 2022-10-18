#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int x,y,z,k,X,Y,Z;

int main(int argc, char *argv[]){
  scanf("%d%d%d%d",&x,&y,&z,&k); 
  int S=(x+y+z-3);
  if(S<k) k=S;
  long long res=0;
  X=0;
  Y=0;
  Z=0;
  while(k){
    if(X<x-1&&(X<=Y||Y==y-1)&&(X<=Z||Z==z-1)) X++;
    else{
      if(Y<y-1&&(Y<=X||X==x-1)&&(Y<=Z||Z==z-1)) Y++;
      else Z++;
    }
    k--;
  }
/*  int M=min((x,y),z),m=max((x,y),z),MM;
  if(3*M<=k){

    X=M; Y=M; Z=M;
  }
  else{ X=M; k-=3*M;
    MM=(S-3*M-(m-M));
    if(MM*2<=k){ Y=MM+M; Z=MM+M; }
    else { Y=M+MM; Z=k-MM+M; }
  }*/
  res=((long long)X+1)*((long long)Y+1)*((long long)Z+1);
  printf("%I64d\n",res);
  return 0;
}