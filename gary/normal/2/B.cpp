#include <bits/stdc++.h>
using namespace std;
struct zeroi{
	int x;
	int y;
};
int two[1010][1010],five[1010][1010],anstwo[1010][1010],ansfive[1010][1010],flag=0;
char fangfatwo[2010][2010],fangfafive[2010][2010],finalfangfa[2010];
long long waytwo=1,wayfive=1,finallen=0;//1 
void dfstwo(int vx,int vy){
	if(vx==1&&vy==1) return;
	if(fangfatwo[vx][vy]=='R'){
		finalfangfa[++finallen]='R';
		dfstwo(vx,vy-1);
	} 
	else{
		finalfangfa[++finallen]='D';
		dfstwo(vx-1,vy);
	}
}
void dfsfive(int vx,int vy){
	if(vx==1&&vy==1) return;
	if(fangfafive[vx][vy]=='R'){
		finalfangfa[++finallen]='R';
		dfsfive(vx,vy-1);
	}
	else{
		finalfangfa[++finallen]='D';
		dfsfive(vx-1,vy);
	}
} 
zeroi one;
int main(){
//	freopen("leastround.in","r",stdin);
//	freopen("leastround.out","w",stdout);
	int n;
	cin>>n;
	memset(two,0,sizeof(two));memset(five,0,sizeof(five));
	memset(ansfive,0,sizeof(ansfive));memset(anstwo,0,sizeof(anstwo)); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long num;
			cin>>num;
			if(num==0){
				one.x =i;one.y =j;
				flag=1;
				continue;
			} 
			while(num%2==0){
				num/=2;
				if (num==0) continue;
				two[i][j]++;
			}
			while(num%5==0){
				num/=5;
				if (num==0) continue;
				five[i][j]++;
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<two[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<five[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i-1>=1&&j-1>=1){
				if(anstwo[i-1][j]+two[i][j]>=anstwo[i][j-1]+two[i][j]){
					anstwo[i][j]=anstwo[i][j-1]+two[i][j];
					fangfatwo[i][j]='R';
					waytwo++;
				}
				else{
					anstwo[i][j]=anstwo[i-1][j]+two[i][j];
					fangfatwo[i][j]='D';
					waytwo++;
				}
				if(ansfive[i-1][j]+five[i][j]>=ansfive[i][j-1]+five[i][j]){
					ansfive[i][j]=ansfive[i][j-1]+five[i][j];
					fangfafive[i][j]='R';
					wayfive++;
				}
				else{
					ansfive[i][j]=ansfive[i-1][j]+five[i][j];
					fangfafive[i][j]='D';
					wayfive++;
				}
			}
			else{
				if(i-1>=1){// 
					anstwo[i][j]=anstwo[i-1][j]+two[i][j]; 
					ansfive[i][j]=ansfive[i-1][j]+five[i][j];
					fangfatwo[i][j]='D';
					fangfafive[i][j]='D';
					waytwo++;wayfive++;
				}
				else if(j-1>=1){// 
					anstwo[i][j]=anstwo[i][j-1]+two[i][j]; 
					ansfive[i][j]=ansfive[i][j-1]+five[i][j];
					fangfatwo[i][j]='R';
					fangfafive[i][j]='R';
					waytwo++;wayfive++;
				}
				else if(i==1&&j==1){// 
					anstwo[i][j]=two[i][j]; 
					ansfive[i][j]=five[i][j];
				}
			}
		}
	}
	if(flag==1&&ansfive[n][n]>=1&&anstwo[n][n]>=1){cout<<"1"<<endl;
		for(int i=1;i<one.y ;i++){
			cout<<"R";
		}
		for(int i=1;i<n;i++){
			cout<<"D";
		}
		for(int i=one.y ;i<n;i++){
			cout<<"R";
		}
		return 0;
	}
	if(ansfive[n][n]>anstwo[n][n]){//two 
		cout<<anstwo[n][n]<<endl;
		dfstwo(n,n);
	}
	else {//five 
		cout<<ansfive[n][n]<<endl;
		dfsfive(n,n);
	}
	for(int i=finallen;i>=1;i--) cout<<finalfangfa[i]; 
	return 0;
}