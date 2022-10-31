#include<stdio.h>
char str[128][128];
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	if(a*b%2){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	bool turn=false;
	if(b%2){
		turn=true;
		int q=a;
		a=b;
		b=q;
		q=c;
		c=d;
		d=q;
	}
	int r=(a/2)*(b/2);
	int D=c;
	if(a%2)D-=b/2;
	if((a%2&&c<b/2)||e+d/2+D/2<r){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for(int i=0;i<a/2;i++){
		for(int j=0;j<b/2;j++){
			if(e){
				str[i*2][j*2]=str[i*2][j*2+1]=str[i*2+1][j*2]=str[i*2+1][j*2+1]='a'+(i+j)%2;
				e--;
			}else if(d/2){
				str[i*2][j*2]=str[i*2+1][j*2]='a'+(i+j)%2;
				str[i*2][j*2+1]=str[i*2+1][j*2+1]='c'+(i+j)%2;
				d-=2;
			}else{
				str[i*2][j*2]=str[i*2][j*2+1]='a'+(i+j)%2;
				str[i*2+1][j*2]=str[i*2+1][j*2+1]='c'+(i+j)%2;
				c-=2;
			}
		}
	}
	if(a%2){
		for(int j=0;j<b;j++){
			str[a-1][j]='e'+(j&2);
		}
	}
	if(turn){
		for(int i=0;i<b;i++){
			for(int j=0;j<a;j++)printf("%c",str[j][i]);
			printf("\n");
		}
	}else{
		for(int i=0;i<a;i++)printf("%s\n",str[i]);
	}
}