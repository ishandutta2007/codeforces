#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define fr first
#define sc second
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+10;
void sol(){
	int a[3];
	rep(i,0,2)scanf("%d",&a[i]);
	sort(a,a+3);
	printf("%s\n",a[2]>a[0]+a[1]+1?"No":"Yes");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}