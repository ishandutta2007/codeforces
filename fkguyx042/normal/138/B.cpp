#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 100010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,an,re,s,an1,sum;
int a[10],b[10],c[10],d[N],e[N];
char p[N];
inline void get(int x,int y) {
	d[++s]=x,e[s]=y;
}
inline void print(int i) {
	For(j,0,9) b[j]=c[j]=a[j];
	b[i]--,c[10-i]--;
	For(j,1,an1) get(0,0);
	get(i,10-i);
	int A=min(min(b[9],c[9]),min(b[0],c[0]));
	For(j,1,A) get(0,9);
	For(j,1,A) get(9,0);
	b[9]-=A,c[9]-=A,b[0]-=A,c[0]-=A;
	A=min(b[0],c[0]);
	b[0]-=A,c[0]-=A;
	For(j,1,8) {
		int B=min(b[j],c[9-j]);
		For(k,1,B) get(j,9-j);
		b[j]-=B,c[9-j]-=B;
	}
	for (;s<n;) {
		For(j,0,9) if (b[j]) break;
		For(k,0,9) if (c[k]) break;
		get(j,k);
		b[j]--,c[k]--;
	}
	for (j=n;j;j--) printf("%d",d[j]); printf("\n");
	for (j=n;j;j--) printf("%d",e[j]); printf("\n");
}
int main() {
	scanf("%s",p+1);
	n=strlen(p+1);
	For(i,1,n) a[p[i]-'0']++;
	an=-1;
	For(i,1,9) if (a[i]&&a[10-i]) {
		For(j,0,9) b[j]=c[j]=a[j];
		b[i]--,c[10-i]--;
		k=1;
		int A=min(min(b[9],c[9]),min(b[0],c[0]));
		k+=A*2;
		b[9]-=A,c[9]-=A,b[0]-=A,c[0]-=A;
		sum=min(b[0],c[0]);
		b[0]-=sum,c[0]-=sum;
		k+=sum;
		For(j,1,8) {
			int B=min(b[j],c[9-j]);
			k+=B;
			b[j]-=B,c[9-j]-=B;
		}
		if (k>an) an=k,re=i,an1=sum;
	}
	if (an<0) {
		For(j,1,9)For(k,1,a[j]) printf("%d",j);
		For(j,1,a[0]) printf("0"); printf("\n");
		For(j,1,9)For(k,1,a[j]) printf("%d",j);
		For(j,1,a[0]) printf("0"); printf("\n");
	} else print(re);
	//for(;;);
	return 0;
}