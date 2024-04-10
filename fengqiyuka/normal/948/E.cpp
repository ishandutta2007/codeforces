#include<cstdio>
#include<cstring>
using namespace std;
char a[210000],b[210000];
int qa[210000],qb[210000],qc[210000],qd[210000];
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	int lena=strlen(a+1),lenb=strlen(b+1);
	qa[0]=0;for(int i=1;i<=lena;i++) qa[i]=qa[i-1]+(a[i]!='A');
	qb[0]=0;for(int i=1;i<=lenb;i++) qb[i]=qb[i-1]+(b[i]!='A');
	qc[0]=0;for(int i=1;i<=lena;i++) qc[i]=a[i]!='A'?0:qc[i-1]+1;
	qd[0]=0;for(int i=1;i<=lenb;i++) qd[i]=b[i]!='A'?0:qd[i-1]+1;
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++) 
	{
		int l1,r1,l2,r2;scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int temp=qa[r1]-qa[l1-1],temp2=qb[r2]-qb[l2-1],temp1,temp3;
		if(r1-qc[r1]<l1) temp1=r1-l1+1;else temp1=qc[r1];
		if(r2-qd[r2]<l2) temp3=r2-l2+1;else temp3=qd[r2];
		if(temp2<temp) printf("0");
		else if(temp2%2!=temp%2) printf("0");
		else if(temp1<temp3) printf("0");
		else if(temp1==temp3&&temp==0&&temp2>0) printf("0");
		else if(temp==temp2&&temp1%3!=temp3%3) printf("0");
		else printf("1");
	}
	printf("\n");
	return 0;
}