#include<bits/stdc++.h>
using namespace std;
const int MAXN=50+5;
int a[MAXN][MAXN],r1,c1,r2,c2,n,ansflag=0;
void make(int x,int y,int num){
	if(ansflag) return; 
	if(a[x][y]!=0&&a[x][y]!=1&&a[x][y]!=num){ansflag=1;return;
	}
	if(x<=0||x>n||y<=0||y>n||a[x][y]) return;
	a[x][y]=num;
	make(x+1,y,num);
	make(x,y+1,num);
	make(x-1,y,num);
	make(x,y-1,num);
}
int main(){
	scanf("%d",&n);scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char tmp;
			cin>>tmp;
			a[i][j]=tmp^48;
		}
	make(r1,c1,2);//go
	make(r2,c2,3);//to
	if(ansflag){
		printf("0\n");
		return 0;
	}
	int r=min(r1,r2),c=max(c1,c2),rr=max(r1,r2),cc=min(c1,c2),rec=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==2){
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						if(a[ii][jj]==3){
							rec=min(rec,(i-ii)*(i-ii)+(j-jj)*(j-jj));
						}
					}
				}
			}
		}
	}
	printf("%d\n",rec);
	return 0;
}