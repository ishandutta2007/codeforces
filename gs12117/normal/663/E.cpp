#include<stdio.h>
#include<vector>
int n,m;
int ans;
int a[1<<20];
char s[23][100100];
std::vector<int> b[500];
void f(int dep,int stp,int r){
	int i,j;
	if(dep==0){
		j=0;
		for(i=0;i<=r;i++){
			if(i<r-i)j+=b[stp+i][0]*i;
			else j+=b[stp+i][0]*(r-i);
		}
		if(ans>j)ans=j;
		return;
	}
	int t=(1<<dep-1),endp=stp+r+1;
	if(b[endp].size()<t){
		for(j=0;j<=r+1;j++){
			for(i=0;i<t;i++){
				b[endp+j].push_back(0);
			}
		}
	}
	for(i=0;i<t;i++){
		b[endp][i]=0;
	}
	for(j=0;j<=r;j++){
		for(i=0;i<t;i++){
			b[endp+j+1][i]=b[stp+j][i+t];
			b[endp+j][i]+=b[stp+j][i];
		}
	}
	f(dep-1,endp,r+1);
	for(i=0;i<t;i++){
		b[endp][i]=0;
	}
	for(j=0;j<=r;j++){
		for(i=0;i<t;i++){
			b[endp+j+1][i]=b[stp+j][i];
			b[endp+j][i]+=b[stp+j][i+t];
		}
	}
	f(dep-1,endp,r+1);
}
int main(){
	int i,j,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	for(i=0;i<m;i++){
		t=0;
		for(j=0;j<n;j++){
			t+=(s[j][i]-'0')<<j;
		}
		a[t]++;
	}
	for(i=0;i<(1<<n);i++){
		b[0].push_back(a[i]);
	}
	ans=999999999;
	f(n,0,0);
	printf("%d",ans);
	return 0;
}