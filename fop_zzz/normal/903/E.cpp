#include<bits/stdc++.h>
using namespace std;
char a[5005][5005];
char c[10],d[10];
int vis[30];
int n,len,T;
void check(){
	bool fl=1;
	for (int k=2;k<=n;k++){
		int s1=0,s2=0;
		for (int l=1;l<=len;l++)
			if (a[k][l]!=a[1][l]){
				c[++s1]=a[k][l];
				d[++s2]=a[1][l];
				if (s1>2) break;
			}
		if (s1>2||s1==1){
			fl=0;
			break;
		}
		else if (s1==0){
			bool fks=0;
			T++;
			for (int l=1;l<=len;l++){
				if (vis[a[k][l]-'a']==T){
					fks=1; break;
				}
				else vis[a[k][l]-'a']=T;
			}
			if (!fks){
				fl=0;
				break;
			}
		}
		else if (c[1]!=d[2]||c[2]!=d[1]){
			fl=0;
			break;
		}
	}
	if (fl){
		printf("%s\n",a[1]+1);
		exit(0);
	} 
}
int main(){
	scanf("%d%d",&n,&len);
	for (int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	if (n==1){
	    swap(a[1][1],a[1][2]);
	    printf("%s",a[1]+1);
	    return 0;
	}
	int sum=0;
	T++;
	bool fuck=0;
	for (int i=1;i<=len;i++)
		if (vis[a[1][i]-'a']==T){
			fuck=1; break;
		}
		else vis[a[1][i]-'a']=T;
	if (fuck) check();
	swap(a[1][1],a[1][2]);
	check();
	swap(a[1][1],a[1][2]);
	for (int i=1;i<=len;i++){
		if (a[1][i]==a[2][i]) continue;
		sum++;
		if (sum>4) continue;
		for (int j=1;j<=len;j++)
			if (j!=i){
				swap(a[1][i],a[1][j]);
				check();
				swap(a[1][i],a[1][j]);
			} 
	}
	puts("-1");
}