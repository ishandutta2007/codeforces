#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	char c[505][505];
	for(int i = 0;i<n;i++){
		scanf("%s",c[i]);
	}
	if(n%3==0){
		for(int i = 1;i<n;i+=3){
			for(int j = 0;j<m;j++)c[i][j]='X';
			
			if(i+3<n){
				int ok=0;
				for(int j  =0;j<m;j++){
					if(c[i+1][j]=='X'){
						c[i+2][j]='X';
						ok=1;
						break;
					}
					if(c[i+2][j]=='X'){
						c[i+1][j]='X';
						ok=1;
						break;
					}	
				}
				if(!ok)c[i+1][0]=c[i+2][0]='X';
			}
			
		}

	}
	else{
		for(int i = 0;i<n;i+=3){
			for(int j = 0;j<m;j++)c[i][j]='X';
			if(i+3<n){
				int ok=0;
				for(int j  =0;j<m;j++){
					if(c[i+1][j]=='X'){
						c[i+2][j]='X';
						ok=1;
						break;
					}
					if(c[i+2][j]=='X'){
						c[i+1][j]='X';
						ok=1;
						break;
					}	
				}
				if(!ok)c[i+1][0]=c[i+2][0]='X';
			}
			
		}
	}
	for(int i = 0;i<n;i++){
		printf("%s\n",c[i]);
	}
}
/*
5 5
2 8
*/
int main(){
		//MEMS(dp);
	int t=10000;//000000;//000000;
    scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}