#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#include<vector>
using namespace std;
struct chess{
	char c;
	long long int x,y;
};
bool cmp(const chess a,const chess b){
	return max(abs(a.x),abs(a.y))<max(abs(b.x),abs(b.y));
}
long long int a[200005],b[200005];
chess ch[500005];
int main(){
	long long int n;
	scanf("%I64d",&n);
	pii king;
	scanf("%I64d %I64d\n",&king.x,&king.y);
	pii d[10];
	for(int i=0;i<10;i++)
	d[i].x=d[i].y=0;
	int ok=0;
	for(int i=0;i<n;i++){
		long long int x,y;
		char c;
		while(scanf("%c",&c)&&(c!='R'&&c!='B'&&c!='Q'));
		scanf("%I64d %I64d",&x,&y);
		ch[i].c=c;
		ch[i].x=x-king.x;
		ch[i].y=y-king.y;
	}
	sort(ch,ch+n,cmp);
	for(int i=0;i<n;i++)
	{
		long long int x,y;
		char c;
		c=ch[i].c;
		x=ch[i].x;
		y=ch[i].y;
		if(c=='R')
		{
			if(x==0){
				if(y>0&&(y<d[8].y||!d[8].y))
				ok=1;
				if(y<0&&(y>d[2].y||!d[2].y))
				ok=1;
			} 
			else if(y==0){
				if(x>0&&(x<d[6].x||!d[6].x))
				ok=1;
				if(x<0&&(x>d[4].x||!d[4].x))
				ok=1;
			}
			else if(x*x==y*y){
				if(x>0&&y>0){
					if(!d[9].x)
					d[9].x=x,d[9].y=y;
					else
					d[9].x=min(d[9].x,x),d[9].y=min(y,d[9].y);
				}
				else if(x<0&&y>0){
					if(!d[7].x)
					d[7].x=x,d[7].y=y;
					else
					d[7].x=max(d[7].x,x),d[7].y=min(y,d[7].y);
				}
				else if(x>0&&y<0){
					if(!d[3].x)
					d[3].x=x,d[3].y=y;
					else
					d[3].x=min(d[3].x,x),d[3].y=max(y,d[3].y);
				}
				else{
					if(!d[1].x)
					d[1].x=x,d[1].y=y;
					else
					d[1].x=max(d[1].x,x),d[1].y=max(y,d[1].y);
				}
			
			}
		}
		else if(c=='B'){
			if(x*x==y*y){
				if(x>0&&y>0){
					if(!d[9].x||(d[9].x>x&&d[9].y>y))
					ok=1;
				}
				else if(x<0&&y>0){
					if(!d[7].x||(d[7].x<x&&d[7].y>y))
					ok=1;
				}
				else if(x>0&&y<0){
					if(!d[3].x||(d[3].x>x&&d[3].y<y))
					ok=1;
				}
				else{
					if(!d[1].x||(d[1].x<x&&d[1].y<y))
					ok=1;
				}
			}
			else if(x==0){
				if(y>0&&(y<d[8].y||!d[8].y)){
					if(!d[8].y)
					d[8].y=y;
					else
					d[8].y=min(d[8].y,y);
				}
				if(y<0&&(y>d[2].y||!d[2].y)){
					if(!d[2].y)
					d[2].y=y;
					else
					d[2].y=max(d[2].y,y);
				}
			} 
			else if(y==0){
				if(x>0&&(x<d[6].x||!d[6].x)){
					if(!d[6].x)
					d[6].x=x;
					else
					d[6].x=min(d[6].x,x);
				}
				if(x<0&&(x>d[4].x||!d[4].x)){
					if(!d[4].x)
					d[4].x=x;
					else
					d[4].x=max(d[4].x,x);
				}
			}
		}
		else if(c=='Q'){
			if(x*x==y*y){
				if(x>0&&y>0){
					if(!d[9].x||(d[9].x>x&&d[9].y>y))
					ok=1;
				}
				else if(x<0&&y>0){
					if(!d[7].x||(d[7].x<x&&d[7].y>y))
					ok=1;
				}
				else if(x>0&&y<0){
					if(!d[3].x||(d[3].x>x&&d[3].y<y)) 
					ok=1;
				}
				else{
					if(!d[1].x||(d[1].x<x&&d[1].y<y)) 
					ok=1;
				}
			}
			else if(x==0){
				if(y>0&&(y<d[8].y||!d[8].y))
				ok=1;
				if(y<0&&(y>d[2].y||!d[2].y))
				ok=1;
			} 
			else if(y==0){
				if(x>0&&(x<d[6].x||!d[6].x))
				ok=1;
				if(x<0&&(x>d[4].x||!d[4].x))
				ok=1;
			}
		}
	}
	printf("%s\n",ok?"YES":"NO");
}/*
7 8 9
4   6
1 2 3 */