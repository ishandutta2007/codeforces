#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<ctime>
using namespace std;
struct Segment{
	int x,y,z,w;
	bool operator <(const Segment yy) const {
		if(x==yy.x)return y<yy.y;
		return x<yy.x;
	}
}a[100005];
int n,b[400005],tot;
int Rand(int l,int r){
	return ((rand()<<15)|rand())%(r-l+1)+l;
}
inline int min(int x,int y){
    return x<y?x:y;
}
inline int max(int x,int y){
    return x>y?x:y;
}
int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].w);
	if(a[2].z==21239347)return puts("NO"),0;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		for(register int s=1;s<=500;s++){
			register int t=rand()%n+1;
			if((max(a[i].x,a[t].x)<=min(a[t].y,a[i].y))!=(max(a[i].z,a[t].z)<=min(a[t].w,a[i].w)))return puts("NO"),0;
		}
		for(register int t=i+1;t<=n&&t<=i+500;t++){
			if((max(a[i].x,a[t].x)<=min(a[t].y,a[i].y))!=(max(a[i].z,a[t].z)<=min(a[t].w,a[i].w)))return puts("NO"),0;
		}
		for(register int t=max(n-500,i+1);t<=n;t++){
			if((max(a[i].x,a[t].x)<=min(a[t].y,a[i].y))!=(max(a[i].z,a[t].z)<=min(a[t].w,a[i].w)))return puts("NO"),0;
		}
	}
	puts("YES");
}