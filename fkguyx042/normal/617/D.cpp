#include<cstdio>
using namespace std;
struct point{
	int x,y;
}p[3];
int main(){
	for(int i=0;i<3;i++)scanf("%d%d",&p[i].x,&p[i].y);
	if((p[0].x==p[1].x)&&(p[0].x==p[2].x)){
		printf("1");
		return 0;
	}
	if((p[0].y==p[1].y)&&(p[0].y==p[2].y)){
		printf("1");
		return 0;
	}
	if(p[0].x==p[1].x){
		if(p[0].y>p[1].y){
			point t=p[0];
			p[0]=p[1];
			p[1]=t;
		}
		if((p[2].y>p[0].y)&&(p[2].y<p[1].y))printf("3");
		else printf("2");
		return 0;
	}
	if(p[1].x==p[2].x){
		if(p[1].y>p[2].y){
			point t=p[1];
			p[1]=p[2];
			p[2]=t;
		}
		if((p[0].y>p[1].y)&&(p[0].y<p[2].y))printf("3");
		else printf("2");
		return 0;
	}
	if(p[0].x==p[2].x){
		if(p[0].y>p[2].y){
			point t=p[0];
			p[0]=p[2];
			p[2]=t;
		}
		if((p[1].y>p[0].y)&&(p[1].y<p[2].y))printf("3");
		else printf("2");
		return 0;
	}
	if(p[0].y==p[1].y){
		if(p[0].x>p[1].x){
			point t=p[0];
			p[0]=p[1];
			p[1]=t;
		}
		if((p[2].x>p[0].x)&&(p[2].x<p[1].x))printf("3");
		else printf("2");
		return 0;
	}
	if(p[1].y==p[2].y){
		if(p[1].x>p[2].x){
			point t=p[1];
			p[1]=p[2];
			p[2]=t;
		}
		if((p[0].x>p[1].x)&&(p[0].x<p[2].x))printf("3");
		else printf("2");
		return 0;
	}
	if(p[0].y==p[2].y){
		if(p[0].x>p[2].x){
			point t=p[0];
			p[0]=p[2];
			p[2]=t;
		}
		if((p[1].x>p[0].x)&&(p[1].x<p[2].x))printf("3");
		else printf("2");
		return 0;
	}
	printf("3");
}