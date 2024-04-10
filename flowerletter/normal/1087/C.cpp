#include <bits/stdc++.h>
using namespace std;
#define Int register int
struct Node{
	int x,y;
}a[10],out[100010];
int ans,cnt;
bool cmp(Node a,Node b){
	return a.x<b.x;
}
bool CMP(Node a,Node b){
	return a.y<b.y;
}
int x,y;
bool is(int a1,int b1,int a2,int b2){
	return( a1==a2 && b1==b2);
}
void write(int a1,int b1,int a2,int b2){
	if(a1<a2) for(Int i=a1;i<=a2;i++) if(!is(b1,i,b2,a2)) printf("%d %d\n",b1,i);
	if(a1>=a2) for(Int i=a2;i<=a1;i++) if(!is(b1,i,b2,a2)) printf("%d %d\n",b1,i);
	if(b1<b2) for(Int i=b1+1;i<b2;i++) if(!is(i,a1,b2,a2)) printf("%d %d\n",i,a2);
	if(b1>=b2) for(Int i=b2+1;i<b1;i++) if(!is(i,a1,b2,a2)) printf("%d %d\n",i,a2);
}
int main(){
	cin>>a[1].y>>a[1].x>>a[2].y>>a[2].x>>a[3].y>>a[3].x;
	ans+=max(max(a[1].x,a[2].x),a[3].x)-min(min(a[1].x,a[2].x),a[3].x);
	ans+=max(max(a[1].y,a[2].y),a[3].y)-min(min(a[1].y,a[2].y),a[3].y);
	cout<<ans+1<<endl;
	sort(a+1,a+3+1,cmp);
	x=a[2].x;
	if(a[1].x==a[2].x){
		int x1=max(max(a[1].x,a[2].x),a[3].x),x2=min(min(a[1].x,a[2].x),a[3].x);
		int y1=max(max(a[1].y,a[2].y),a[3].y),y2=min(min(a[1].y,a[2].y),a[3].y);
		for(Int i=y2;i<=y1;i++) printf("%d %d\n",i,a[2].x);
		for(Int i=x1;i>x2;i--) printf("%d %d\n",a[3].y,i);
		return 0;
	}
	if(a[3].x==a[2].x){
		int x1=max(max(a[1].x,a[2].x),a[3].x),x2=min(min(a[1].x,a[2].x),a[3].x);
		int y1=max(max(a[1].y,a[2].y),a[3].y),y2=min(min(a[1].y,a[2].y),a[3].y);
		for(Int i=y2;i<=y1;i++) printf("%d %d\n",i,a[2].x);
		for(Int i=x2;i<x1;i++) printf("%d %d\n",a[1].y,i);
		return 0;
	}
	sort(a+1,a+3+1,CMP);
	y=a[2].y;
	if(a[1].y==a[2].y){
		int x1=max(max(a[1].x,a[2].x),a[3].x),x2=min(min(a[1].x,a[2].x),a[3].x);
		int y1=max(max(a[1].y,a[2].y),a[3].y),y2=min(min(a[1].y,a[2].y),a[3].y);
		for(Int i=x2;i<=x1;i++) printf("%d %d\n",a[2].y,i);
		for(Int i=y1;i>y2;i--) printf("%d %d\n",i,a[3].x);
		return 0;
	}
	if(a[3].y==a[2].y){
		int x1=max(max(a[1].x,a[2].x),a[3].x),x2=min(min(a[1].x,a[2].x),a[3].x);
		int y1=max(max(a[1].y,a[2].y),a[3].y),y2=min(min(a[1].y,a[2].y),a[3].y);
		for(Int i=x2;i<=x1;i++) printf("%d %d\n",a[2].y,i);
		for(Int i=y2;i<y1;i++) printf("%d %d\n",i,a[1].x);
		return 0;
	}
	else {
		printf("%d %d\n",y,x);
		write(a[1].x,a[1].y,x,y);
		write(a[2].x,a[2].y,x,y);
		write(a[3].x,a[3].y,x,y);
	}
	return 0;
}