#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 40000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define inf 1000000000
#define eps 1e-8
using namespace std;
int x,y,z;
int main(){
	scanf("%d%d%d",&x,&y,&z);
	if(x<y)swap(x,y);if(x<z)swap(x,z);
	printf("%d",max(0,x+1-y-z));
}