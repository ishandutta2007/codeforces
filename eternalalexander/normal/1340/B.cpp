#include <bits/stdc++.h>
int f[2005][2005],n,k;
char s[2005][20];

char A[10][10]=
{"1110111", "0010010", "1011101", "1011011", "0111010", 
"1101011", "1101111", "1010010", "1111111", "1111011"};

int match(int i,int N){
	int ans=0;
	for(int j=0;j<8;++j){
		if(A[N][j]=='0'&&s[i][j]=='1')return -1;
		if(A[N][j]=='1'&&s[i][j]=='0')ans++;
	}return ans;
}

void output(int x,int y){
	if(x>n)return;
	for(int l=9;l>=0;--l){
		int d=match(x,l);
		if(d==-1||y<d||!f[x+1][y-d])continue;
		printf("%d",l);
		output(x+1,y-d);
		return;
	}
}
		

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]);
	f[n+1][0]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=k;j++){
			for(int l=0;l<=9;++l){
				int d=match(i,l);
				if(d==-1||j<d)continue;
				f[i][j]|=f[i+1][j-d];
			}
		}
	}if(!f[1][k]){puts("-1");return 0;}
	output(1,k);
	return 0;
}