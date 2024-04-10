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
	int n;
	scanf("%d",&n);
	int a,b;
	scanf("%d %d",&a,&b);
	char c[100005];
	scanf("%s",c);
	printf("%d\n",c[a-1]==c[b-1]?0:1);
}