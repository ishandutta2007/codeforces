#include<bits/stdc++.h>
using namespace std;
int n,a[5001],c[5001],n1/*1,1*/,n2/*1,0*/,n3/*0,1*/,n4/*0,0*/;
int main(){char tmpc;
	scanf("%d",&n);
	tmpc=getchar();
	for(int i=1;i<=n;i++) {
		tmpc=getchar();
		c[i]=int(tmpc^48);
	}
	tmpc=getchar();
	for(int i=1;i<=n;i++){
		tmpc=getchar();
		a[i]=int(tmpc^48); 
	}	
	for(int i=1;i<=n;i++){
		if(c[i]){
			if(a[i]){
				n1++;
			}
			else n2++;
		}
		else{
			if(a[i]){
				n3++;
			}
			else n4++;
		}
	}
//	a b c d
//	c:a+b
//	a:(n1-a)+(n3-c);
//	a+b=n1-a+n3-c
//	2a+b+c=n1+n3
	for(int A=0;A<=n1;++A){
		for(int B=0;B<=n2;++B){
			int C=n1+n3-2*A-B;
			if(C<=n3&&C>=0&&C+A+B<=n/2){
				int d=n/2-A-B-C;
				if(d>n4) continue;
				for(int i=1;i<=n;++i){
					if(c[i]){//1
						if(a[i]){
							if(A){
							--A;
							printf("%d ",i);
						}
						}
						else{
							if(B){
							--B;
							printf("%d ",i);
						}
						}
					}
					else{
						if(a[i]){
							if(C){
							--C;
							printf("%d ",i);
						}
						}
						else{
							if(d){
							--d;
							printf("%d ",i);
						}
						}
					}
				}
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}