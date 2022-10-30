#include <stdio.h>
#define max(x,y) (x>y?x:y)
struct XD{
	char c[25]; int n,ta,pi,gl;
	XD(){ ta=pi=gl=0; }
}bx[101];
char tmp[25];
int maxgl,maxta,maxpi,n,got;
int main(){
	scanf("%d",&n);
	for( int i=0;i<n;i++ ){
		scanf("%d %s",&bx[i].n,bx[i].c);
		for( int j=0;j<bx[i].n;j++ ){
			scanf("%s",tmp);
			if(tmp[0]==tmp[1]&&tmp[1]==tmp[3]&&tmp[3]==tmp[4]&&
				tmp[4]==tmp[6]&&tmp[6]==tmp[7]) bx[i].ta++;
			else if(tmp[0]>tmp[1]&&tmp[1]>tmp[3]&&tmp[3]>tmp[4]&&
				tmp[4]>tmp[6]&&tmp[6]>tmp[7]) bx[i].pi++;
			else bx[i].gl++;
		}
		maxgl=max(maxgl,bx[i].gl);
		maxta=max(maxta,bx[i].ta);
		maxpi=max(maxpi,bx[i].pi);
	}
	printf("If you want to call a taxi, you should call:"); got=0;
	for( int i=0;i<n;i++ ) if( bx[i].ta==maxta ){
		if(got) putchar(','); got++; printf(" %s",bx[i].c);
	} puts("."); got=0;
	printf("If you want to order a pizza, you should call:");
	for( int i=0;i<n;i++ ) if( bx[i].pi==maxpi ){
		if(got) putchar(','); got++; printf(" %s",bx[i].c);
	} puts("."); got=0;
	printf("If you want to go to a cafe with a wonderful girl, you should call:");
	for( int i=0;i<n;i++ ) if( bx[i].gl==maxgl ){
		if(got) putchar(','); got++; printf(" %s",bx[i].c);
	} puts(".");
}