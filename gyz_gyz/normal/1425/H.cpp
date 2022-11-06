#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d,op,mm,f[4];
int main()
{
	scanf("%d",&T);
	while(T--){
		mm=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if((a+b)%2==0)op=1;
		else op=-1;
		if(b+c>0)mm+=1;
		if(a+d>0)mm+=2;
		if(op==1)f[0]=f[1]=0,f[2]=f[3]=1;
		else f[0]=f[1]=1,f[2]=f[3]=0;
		if(mm==1)f[0]=f[3]=0;
		if(mm==2)f[1]=f[2]=0;
		for(int i=0;i<4;i++)
			printf("%s%c",f[i]?"Ya":"Tidak",i<3?' ':'\n');
	}
}