#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define eps 1e-18
using namespace std;
int x,y,x1,y1,x2,y2;
int main(){
	scanf("%d",&x);
	scanf("%d%d",&x,&y);
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	if((abs(x-x1)/(x-x1)==abs(x-x2)/(x-x2))&&
	(abs(y-y1)/(y-y1)==abs(y-y2)/(y-y2)))printf("YES");else printf("NO");
}