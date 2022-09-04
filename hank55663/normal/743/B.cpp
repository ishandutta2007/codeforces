#include<bits/stdc++.h>
#define pii pair<int,int>    
#define x first    
#define y second    
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))    
#define sqr(x) ((x)*(x))
typedef long long LL;  
using namespace std;
vector<pii> v[100005];
long long int input()   
{   
  char cha;   
  unsigned long long int x=0;   
  while(cha=getchar())   
     if(cha!=' '&&cha!='\n') break;   
  x=cha-48;   
  while(cha=getchar())    
    {   
     if(cha==' '||cha=='\n') break;   
      x=x*10+cha-48;   
    }   
    return x;   
}
int main(){
	long long int n,k;
	n=input(),k=input();
	int ans=1;
	while(k%2==0)k/=2,ans++;
	printf("%d\n",ans)
;	
}