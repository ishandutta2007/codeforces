#include<bits/stdc++.h>
using namespace std;
int r,c;
char a[510][510];
int main(int argc,char**argv){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
			if(a[i][j]=='S')
				if(a[i][j-1]=='W'|a[i-1][j]=='W')return printf("No"),0;
			if(a[i][j]=='W')
				if(a[i][j-1]=='S'|a[i-1][j]=='S')return printf("No"),0;
			if(a[i][j]=='.')a[i][j]='D';
		}
	puts("Yes");
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++)putchar(a[i][j]);
		puts("");
	}
}