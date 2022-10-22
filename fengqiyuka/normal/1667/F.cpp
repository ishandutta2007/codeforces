#include<bits/stdc++.h>
using namespace std;

const int N=510;
char s[N][N],sta[4*N];int n,m,tot,X[N*4],Y[N*4];

bool check(){
	for(int i=1;i<=n;i++){
		if(s[i][1]=='B') return false;
	}
	int tot2=0;
	for(int i=2;i<=m;i++) X[++tot2]=1,Y[tot2]=i;
	for(int i=2;i<=n;i++) X[++tot2]=i,Y[tot2]=m;
	for(int i=m-1;i>=2;i--) X[++tot2]=n,Y[tot2]=i;
	
	int id1=0,id2=tot2+1;
	for(int i=1;i<=tot2;i++){
		if(s[X[i]][Y[i]]=='B') break;
		id1++;
	}
	for(int i=tot2;i>=1;i--){
		if(s[X[i]][Y[i]]=='B') break;
		id2--;
	}
	
	id1++;id2--;
	
	if(id1>id2) return true;
	for(int i=id1;i<=id2;i++)
		if(s[X[i]][Y[i]]=='W') return false;
	
	return true;
}

int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		
		tot=0;
		for(int i=1;i<=m;i++)
			if(s[1][i]!='.') sta[++tot]=s[1][i];
		for(int i=2;i<=n;i++)
			if(s[i][m]!='.') sta[++tot]=s[i][m];
		for(int i=m-1;i>=1;i--)
			if(s[n][i]!='.') sta[++tot]=s[n][i];
		for(int i=n-1;i>=2;i--)
			if(s[i][1]!='.') sta[++tot]=s[i][1];
		
		bool pd=true;int Sum=0;
		for(int i=1;i<tot;i++)
			if(sta[i]!=sta[i+1]){
				Sum++;
				if(Sum>=3) {pd=false;break;}
			}
			
		if(!pd){
			printf("NO\n");
			continue;
		}
		
		printf("YES\n");
		
		int flag=0,PD=0;
		if(!check()){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m/2;j++) swap(s[i][j],s[i][m+1-j]);
			PD=1;
		}
		if(!check()){
			for(int i=1;i<=mymax(n,m);i++)
				for(int j=1;j<=mymax(n,m);j++)
					if(i>j) swap(s[i][j],s[j][i]);
			swap(n,m);
			PD=3;
		}
		if(!check()){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m/2;j++) swap(s[i][j],s[i][m+1-j]);
			PD=2;
		}
		if(!check()){
			flag=1;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++){
					if(s[i][j]=='B') s[i][j]='W';
					else if(s[i][j]=='W') s[i][j]='B';
				}
			for(int i=1;i<=tot;i++){
				if(sta[i]=='B') sta[i]='W';
				else sta[i]='B';
			}
			
			for(int i=1;i<=mymax(n,m);i++)
				for(int j=1;j<=mymax(n,m);j++)
					if(i>j) swap(s[i][j],s[j][i]);
					
			swap(n,m);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m/2;j++) swap(s[i][j],s[i][m+1-j]);
			for(int i=1;i<=n/2;i++)
				for(int j=1;j<=m;j++) swap(s[i][j],s[n+1-i][j]);
			PD=0;
		}
		if(!check()){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m/2;j++) swap(s[i][j],s[i][m+1-j]);
			PD=1;
		}
		if(!check()){
			for(int i=1;i<=mymax(n,m);i++)
				for(int j=1;j<=mymax(n,m);j++)
					if(i>j) swap(s[i][j],s[j][i]);
			swap(n,m);
			PD=3;
		}
		if(!check()){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m/2;j++) swap(s[i][j],s[i][m+1-j]);
			PD=2;
		}
		
		int tot2=0;
		for(int i=2;i<=m;i++) X[++tot2]=1,Y[tot2]=i;
		for(int i=2;i<=n;i++) X[++tot2]=i,Y[tot2]=m;
		for(int i=m-1;i>=2;i--) X[++tot2]=n,Y[tot2]=i;
		
		for(int i=1;i<=n;i++) s[i][1]='W';
		
		int las=1;pd=true;
		for(int i=1;i<=tot2;i++){
			if(s[X[i]][Y[i]]=='W'){
				for(int j=las;j<=i;j++)
					s[X[j]][Y[j]]='W';
				las=i+1;
			}
			else if(s[X[i]][Y[i]]=='B') {pd=false;break;}
		}
		if(!pd){
			las=tot2;
			for(int i=tot2;i>=1;i--){
				if(s[X[i]][Y[i]]=='W'){
					for(int j=las;j>=i;j--)
						s[X[j]][Y[j]]='W';
					las=i-1;
				}
				else if(s[X[i]][Y[i]]=='B') break;
			}
		}
		for(int i=1;i<=tot2;i++)
			if(s[X[i]][Y[i]]!='W') s[X[i]][Y[i]]='B';
			
		for(int i=2;i<m;i++){
			if(s[2][i]=='B'&&s[1][i]=='W'){
				if(s[2][i-2]=='B') s[2][i-1]='B';
				else if(s[4][i]=='W'){
					if(i<=m-2) s[2][i+1]=s[3][i+1]='B';
					else s[2][i-1]=s[3][i-1]='B';
				}
				else s[3][i]='B';
			}
			if(s[n-1][i]=='B'&&s[n][i]=='W'){
				if(s[n-1][i-2]=='B') s[n-1][i-1]='B';
				else if(s[n-3][i]=='W'){
					if(i<=m-2) s[n-2][i+1]=s[n-1][i+1]='B';
					else s[n-2][i-1]=s[n-1][i-1]='B';
				}
				else s[n-2][i]='B';
			}
		}
		
		for(int i=1;i<=n-3;i+=4){
			if(i==1&&s[1][m]!='B') continue;
			if(i+3==n&&s[i+3][m]!='B') continue;
			if(s[i][m]=='W'||s[i+3][m]=='W'){
				if(s[i][m-1]=='W'&&s[i+2][m-1]=='W') s[i+1][m-2]=s[i+2][m-2]='B';
				else if(s[i+1][m-1]=='W'&&s[i+3][m-1]=='W') s[i+1][m-2]=s[i+2][m-2]='B';
				else if(s[i][m-1]=='W'&&s[i+3][m-1]=='W') s[i+1][m-2]=s[i+2][m-2]='B';
				else if(s[i][m-1]=='W'){
					if(s[i+2][m-2]=='W'||s[i+3][m-2]=='W'){
						s[i+1][m-2]=s[i+1][m-1]=s[i+2][m-1]='B';
					}
					else s[i+1][m-2]=s[i+2][m-2]='B';
					if(s[i][m]=='B') s[i][m]=s[i+1][m]=s[i+2][m]='W';
				}
				else if(s[i+3][m-1]=='W'){
					if(s[i+1][m-2]=='W'||s[i][m-2]=='W'){
						s[i+2][m-2]=s[i+1][m-1]=s[i+2][m-1]='B';
					}
					else s[i+1][m-2]=s[i+2][m-2]='B';
					if(s[i+3][m]=='B') s[i+1][m]=s[i+2][m]=s[i+3][m]='W';
				}
				else if(s[i+1][m-1]=='W'){
					if(s[i+1][m]=='B') s[i+2][m-1]='B';
					else{
						s[i+1][m-2]=s[i+2][m-2]=s[i+2][m-1]='B';
						if(s[i+3][m-2]=='W'){
							s[i+3][m-1]=s[i+2][m-1]='W',s[i+2][m-3]=s[i+2][m-2]='B';
							if(s[i+1][m-3]!='W'&&s[i][m-3]!='W') s[i+1][m-3]='B',s[i+2][m-2]='W';
						}
					}
				}
				else if(s[i+2][m-1]=='W'){
					if(s[i+2][m]=='B') s[i+1][m-1]='B';
					else{
						s[i+1][m-2]=s[i+2][m-2]=s[i+1][m-1]='B';
						if(s[i][m-2]=='W'){
							s[i][m-1]=s[i+1][m-1]='W',s[i+1][m-3]=s[i+1][m-2]='B';
							if(s[i+2][m-3]!='W'&&s[i+3][m-3]!='W') s[i+2][m-3]='B',s[i+1][m-2]='W';
						}
					}
				}
				else s[i+1][m-1]=s[i+2][m-1]='B';
			}
		}
		
		for(int i=2;i<m;i++){
			if(s[1][i]=='B'&&s[1][i+1]=='W'){
				if(s[3][i]=='W'){
					if(i<=m-2) s[2][i]=s[2][i+1]=s[3][i+1]='B';
					else s[2][i]=s[2][i-1]=s[3][i-1]='B';
				}
				else if(s[4][i]=='W'){
					if(i<=m-2) s[2][i]=s[2][i+1]=s[3][i+1]='B';
					else{
						s[2][i]=s[3][i]=s[3][i-1]='B';
						if(s[2][i-1]!='W') s[2][i-1]='B';
					}
				}
				else s[2][i]=s[3][i]='B';
			}
			if(s[n][i]=='B'&&s[n][i+1]=='W'){
				if(s[n-2][i]=='W'){
					if(i<=m-2) s[n-1][i]=s[n-1][i+1]=s[n-2][i+1]='B';
					else s[n-1][i]=s[n-1][i-1]=s[n-2][i-1]='B';
				}
				else if(s[n-3][i]=='W'){
					if(i<=m-2) s[n-1][i]=s[n-1][i+1]=s[n-2][i+1]='B';
					else{
						s[n-1][i]=s[n-2][i]=s[n-2][i-1]='B';
						if(s[n-1][i-1]!='W') s[n-1][i-1]='B';
					}
				}
				else s[n-1][i]=s[n-2][i]='B';
			}
		}
		
		for(int i=2;i<n;i++)
			for(int j=2;j<m;j++){
				if(s[i][j]=='.'){
					if(i%4==2||i%4==3) s[i][j]='W';
					else s[i][j]='B';
				}
			}
		
		if(flag){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++){
					if(s[i][j]=='W') s[i][j]='B';
					else s[i][j]='W';
				}
		}
		if(PD==2){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m/2;j++) swap(s[i][j],s[i][m+1-j]);
			PD=3;
		}
		if(PD==3){
			for(int i=1;i<=mymax(n,m);i++)
				for(int j=1;j<=mymax(n,m);j++)
					if(i>j) swap(s[i][j],s[j][i]);
			swap(n,m);
			PD=1;
		}
		if(PD==1){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m/2;j++) swap(s[i][j],s[i][m+1-j]);
			PD=1;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) printf("%c",s[i][j]);
			printf("\n");
		}
	}
	
	return 0;
}