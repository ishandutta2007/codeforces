#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
char s[N];
int qz1[N],qz2[N];

int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	
	for(int i=1;i<=n;i++){
		qz1[i]=qz1[i-1]+(s[i]=='0'&&s[i+1]=='0');
		qz2[i]=qz2[i-1]+(s[i]=='1'&&s[i+1]=='1');
	}
	
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",mymax(qz2[r-1]-qz2[l-1],qz1[r-1]-qz1[l-1])+1);
	}
	
	return 0;
}