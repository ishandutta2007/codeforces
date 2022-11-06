#include<bits/stdc++.h>
#define N 300010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x=x*fh;
}
char ch[N],an[N],p[10],no[N];
int m,n,ansn;
int main(){
	cin>>n>>m;
	p[1]='A';p[2]='C';p[3]='T';p[4]='G';
	for (int i=1;i<=n*m;i++)cin>>ch[i];
	for (int n1=1;n1<4;n1++){
		for (int n2=n1+1;n2<=4;n2++){
			int n3,n4;
			if (n1==1&&n2==2)n3=3,n4=4;
			if (n1==1&&n2==3)n3=2,n4=4;
			if (n1==1&&n2==4)n3=2,n4=3;
			if (n1==2&&n2==3)n3=1,n4=4;
			if (n1==2&&n2==4)n3=1,n4=3;
			if (n1==3&&n2==4)n3=1,n4=2;
			for (int i=1;i<=n;i++){
				if (i%2==1){
					int an1=0,an2=0;
					for (int j=1;j<=m;j++){
						if (j%2==1&&ch[(i-1)*m+j]==p[n1])an1++;
						if (j%2==0&&ch[(i-1)*m+j]==p[n2])an1++;
						if (j%2==0&&ch[(i-1)*m+j]==p[n1])an2++;
						if (j%2==1&&ch[(i-1)*m+j]==p[n2])an2++;
					}
					if (an1>=an2)for (int j=1;j<=m;j++)if (j%2==1)no[(i-1)*m+j]=p[n1];else no[(i-1)*m+j]=p[n2];
					else for (int j=1;j<=m;j++)if (j%2==1)no[(i-1)*m+j]=p[n2];else no[(i-1)*m+j]=p[n1];
				}else{
					int an1=0,an2=0;
					for (int j=1;j<=m;j++){
						if (j%2==1&&ch[(i-1)*m+j]==p[n3])an1++;
						if (j%2==0&&ch[(i-1)*m+j]==p[n4])an1++;
						if (j%2==0&&ch[(i-1)*m+j]==p[n3])an2++;
						if (j%2==1&&ch[(i-1)*m+j]==p[n4])an2++;
					}
					if (an1>=an2)for (int j=1;j<=m;j++)if (j%2==1)no[(i-1)*m+j]=p[n3];else no[(i-1)*m+j]=p[n4];	
					else for (int j=1;j<=m;j++)if (j%2==1)no[(i-1)*m+j]=p[n4];else no[(i-1)*m+j]=p[n3];			
				}
			}
			int su=0;
			for (int i=1;i<=n*m;i++)if (ch[i]==no[i])su++;
			if (su>ansn){ansn=su;for(int i=1;i<=n*m;i++)an[i]=no[i];}
			for (int i=1;i<=m;i++){
				if (i%2==1){
					int an1=0,an2=0;
					for (int j=1;j<=n;j++){
						if (j%2==1&&ch[(j-1)*m+i]==p[n1])an1++;
						if (j%2==0&&ch[(j-1)*m+i]==p[n2])an1++;
						if (j%2==0&&ch[(j-1)*m+i]==p[n1])an2++;
						if (j%2==1&&ch[(j-1)*m+i]==p[n2])an2++;
					}
					if (an1>=an2)for (int j=1;j<=n;j++)if (j%2==1)no[(j-1)*m+i]=p[n1];else no[(j-1)*m+i]=p[n2];
					else for (int j=1;j<=n;j++)if (j%2==1)no[(j-1)*m+i]=p[n2];else no[(j-1)*m+i]=p[n1];
				}else{
					int an1=0,an2=0;
					for (int j=1;j<=n;j++){
						if (j%2==1&&ch[(j-1)*m+i]==p[n3])an1++;
						if (j%2==0&&ch[(j-1)*m+i]==p[n4])an1++;
						if (j%2==0&&ch[(j-1)*m+i]==p[n3])an2++;
						if (j%2==1&&ch[(j-1)*m+i]==p[n4])an2++;
					}
					if (an1>=an2)for (int j=1;j<=n;j++)if (j%2==1)no[(j-1)*m+i]=p[n3];else no[(j-1)*m+i]=p[n4];		
					else for (int j=1;j<=n;j++)if (j%2==1)no[(j-1)*m+i]=p[n4];else no[(j-1)*m+i]=p[n3];		
				}
			}
			su=0;
			for (int i=1;i<=n*m;i++)if (ch[i]==no[i])su++;
			if (su>ansn){ansn=su;for(int i=1;i<=n*m;i++)an[i]=no[i];}
		}
	}
	for (int i=1;i<=n*m;i++){
		cout<<an[i];if (i%m==0)puts("");
	}
	return 0;
}