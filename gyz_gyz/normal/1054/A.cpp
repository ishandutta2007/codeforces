#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define N 131072
#define ll long long
#define mo 1000000007
#define inf 1000000000
using namespace std;
int x,y,z,t1,t2,t3;
int main(){
	scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
	if((abs(x-z)+abs(x-y))*t2+t3*3<=abs(x-y)*t1)printf("YES");else printf("NO");
}