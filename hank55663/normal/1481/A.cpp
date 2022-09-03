#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int x,y;
	scanf("%d %d",&x,&y);
	int x1=0,x2=0,y1=0,y2=0;
	char c[100005];
	scanf("%s",c);
	for(int i = 0;c[i]!=0;i++){
		if(c[i]=='U')y1++;
		if(c[i]=='D')y2++;
		if(c[i]=='R')x1++;
		if(c[i]=='L')x2++;
	}
	int ok=1;
	if(x<0){
		if(x2<abs(x))ok=0;
	}
	else if(x>0){
		if(x1<x)ok=0;
	}
	if(y<0){
		if(y2<abs(y))ok=0;
	}
	else if(y>0){
		if(y1<y)ok=0;
	}
	if(ok)printf("YES\n");
	else printf("NO\n");
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*

*/