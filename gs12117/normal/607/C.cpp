#include<stdio.h>
int n;
char a[1001000];
char b[1001000];
char c[1001000];
long long int fha,fhb,fhc;
long long int dha,dhb,dhc;
long long int ma=100000007;
long long int mb=13838413;
long long int mc=10007;
long long int pab,pba,pac,pca,pbc,pcb;
int main(){
	int i,j;
	scanf("%d",&n);
	n--;
	scanf("%s%s",a,b);
	pab=1;
	pbc=1;
	pca=1;
	pac=1;
	pba=1;
	pcb=1;
	for(i=0;i<n;i++){
		if(b[n-i-1]=='N'){
			c[i]='S';
		}
		if(b[n-i-1]=='E'){
			c[i]='W';
		}
		if(b[n-i-1]=='W'){
			c[i]='E';
		}
		if(b[n-i-1]=='S'){
			c[i]='N';
		}
		fha*=mb;
		fha+=pca*a[n-i-1];
		fhb*=mc;
		fhb+=pab*a[n-i-1];
		fhc*=ma;
		fhc+=pbc*a[n-i-1];
		dha*=mc;
		dha+=pba*c[i];
		dhb*=ma;
		dhb+=pcb*c[i];
		dhc*=mb;
		dhc+=pac*c[i];
		fha%=ma;
		fhb%=mb;
		fhc%=mc;
		dha%=ma;
		dhb%=mb;
		dhc%=mc;
		pab*=ma;
		pbc*=mb;
		pca*=mc;
		pac*=ma;
		pba*=mb;
		pcb*=mc;
		pab%=mb;
		pbc%=mc;
		pca%=ma;
		pac%=mc;
		pba%=ma;
		pcb%=mb;
		if(fha==dha&&fhb==dhb&&fhc==dhc){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}