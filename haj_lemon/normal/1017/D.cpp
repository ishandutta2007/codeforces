#include<bits/stdc++.h>
using namespace std;
long long a[20],b[10010],g[10010],n,m,q,f[4500][1300],x,y;
int get(){
	char ch=getchar();int sum=0;
	while (ch!='0'&&ch!='1') ch=getchar();
	for (int i=1;i<=n;i++){sum+=(1<<(i-1))*(ch-'0');ch=getchar();}
	return sum;
}
int main(){
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=m;i++){b[get()]++;}
	for (int i=0;i<(1<<n);i++){
		for (int j=1,k=1;j<=n;j++,k*=2){
			if ((i&k)!=0)g[i]+=a[j];
		}
	}
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<(1<<n);j++)f[i][g[(1<<n)-(i^j)-1]]+=b[j];
	for (int i=0;i<(1<<n);i++)
		for (int j=1;j<=n*100;j++)f[i][j]+=f[i][j-1];
	while (q--){
		x=get();scanf("%d",&y);
		printf("%d\n",f[x][y]);
	}
	return 0;
}
/*
2 4 5
40 20
01
01
10
11
00 20
00 40
11 20
11 40
11 60
*/