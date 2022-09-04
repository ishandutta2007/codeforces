#include<bits/stdc++.h>
using namespace std;
main(){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	a*=2;
	d*=2;
	int z=-1,o=-1;
	for(long long int i=0;i<1000000;i++){
		if(i*(i+1)==a)
		z=i+1;
		if(i*(i+1)==d)
		o=i+1;
	}
	if(b==0&&c==0){
		if(a!=0&&d==0&&z!=-1){
			for(int i=0;i<z;i++)
			printf("0");
			return 0;
		}
		if(a==0&&d!=0&&o!=-1){
			for(int i=0;i<o;i++)
			printf("1");
			return 0;
		}
		else if(a==0&&d==0){
			printf("1");
			return 0;
		}
	}
	if(z==-1||o==-1||(z+o)*(z+o-1)!=a+d+b*2+c*2){
	printf("Impossible\n");
	return 0;} 
	int k=z+o;
	for(int i=0;i<k;i++){
		if(b>=o)
		{
			printf("0");
			b-=o;
		}
		else{
			printf("1");
			o--;
		}
	}
}