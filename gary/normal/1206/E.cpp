//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define cc fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
int ty;
int res[55][55];
int main(){
	cin>>n;
	res[1][1]=1,res[n][n]=0;
	for(int i=3;i<=n;i+=2){
		printf("? 1 %d 1 %d\n",i-2,i);cc;
		cin>>ty;
		res[1][i]=res[1][i-2];
		if(!ty) res[1][i]^=1;
	}
//	cout<<"F"<<endl;
	for(int i=2;i<=n;i+=1){
		int start;
		if(i%2==1) start=1;
		else start=2;
		for(int j=start;j<=n;j+=2){
			if(i==n&&j==n) continue;
			if(j==1){
//				cout<<"is"<<endl;
				printf("? %d 1 %d 1\n",i-2,i);cc;cin>>ty;
				res[i][1]=res[i-2][1];
				if(!ty) res[i][1]^=1;
			}
			else{
				if(j==2){
					printf("? %d %d %d %d\n",i-1,j-1,i,j);cc;cin>>ty;
				res[i][j]=res[i-1][j-1];
				if(!ty) res[i][j]^=1; 
				}
				else{
				printf("? %d %d %d %d\n",i,j-2,i,j);cc;cin>>ty;
				res[i][j]=res[i][j-2];
				if(!ty) res[i][j]^=1; 	
				}
				
			}
		}
	}
	res[2][1]=1;//tmp;
	for(int i=2;i<=n;i+=1){
		int start;
		if(i%2==1) start=2;
		else start=1;
		for(int j=start;j<=n;j+=2){
			if(i==2&&j==1) continue;
//			cout<<i<<" "<<j<<endl;
			if(j==1){
				printf("? %d 1 %d 1\n",i-2,i);cc;cin>>ty;
				res[i][1]=res[i-2][1];
				if(!ty) res[i][1]^=1;
			}
			else{
				if(j==2){
//					cout<<i<<" "<<j<<"Fuck"<<endl;
					printf("? %d %d %d %d\n",i-1,j-1,i,j);cc;cin>>ty;
					res[i][j]=res[i-1][j-1];
					if(!ty) res[i][j]^=1; 
				}
				else {
//					cout<<i<<" "<<j<<"Fuck2"<<endl;
				printf("? %d %d %d %d\n",i,j-2,i,j);cc;cin>>ty;
				res[i][j]=res[i][j-2];
				if(!ty) res[i][j]^=1; 
				}
			}
		}
	}
	cout<<"? 1 2 2 3"<<endl;cc;
	cin>>ty;
	res[1][2]=res[2][3];
	if(!ty) res[1][2]^=1;int Xor=0;
	for(int i=4;i<=n;i+=2){
		printf("? 1 %d 1 %d\n",i-2,i);cc;cin>>ty;
		res[1][i]=res[1][i-2];
		if(!ty) res[1][i]^=1;
	}
	bool OK=0;
	rb(i,1,n){
		rb(j,1,n){
			if(OK) break;
			if(i+4-1<=n){
				/*
				@
				@
				@
				@
				*/
				if(res[i][j]==res[i+3][j]&&res[i+1][j]==res[i+2][j]){
					printf("? %d %d %d %d\n",i,j,i+3,j);cc;
					cin>>ty;
					if(!ty) Xor=1;
					OK=1;
					break;
				}
				if((res[i][j]^1)==res[i+3][j]&&(res[i+1][j]^1)==res[i+2][j]){
					printf("? %d %d %d %d\n",i,j,i+3,j);cc;
					cin>>ty;
					if(ty) Xor=1;
					OK=1;
					break;
				}
			}
			if(i+3-1<=n&&j+1<=n){
				/*
				@@
				@@
				@@
				*/
				if(res[i][j]==res[i+2][j+1]&&res[i+1][j]==res[i+1][j+1]){
					printf("? %d %d %d %d\n",i,j,i+2,j+1);cc;
					cin>>ty;
					if(!ty) Xor=1;
					OK=1;
					break;
				}
				if((res[i][j]^1)==res[i+2][j+1]&&(res[i+1][j]^1)==res[i+1][j+1]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+2,j+1);cc;
					cin>>ty;
					if(ty) Xor=1;
					break;
				}
				if(res[i][j]==res[i+2][j+1]&&res[i+1][j]==res[i+2][j]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+2,j+1);cc;
					cin>>ty;
					if(!ty) Xor=1;
					break;
				}
				if((res[i][j]^1)==res[i+2][j+1]&&(res[i+1][j]^1)==res[i+2][j]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+2,j+1);cc;
					cin>>ty;
					if(ty) Xor=1;
					break;
				}
				if(res[i][j]==res[i+2][j+1]&&res[i][j+1]==res[i+1][j+1]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+2,j+1);cc;
					cin>>ty;
					if(!ty) Xor=1;
					break;
				}
				if((res[i][j]^1)==res[i+2][j+1]&&(res[i][j+1]^1)==res[i+1][j+1]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+2,j+1);cc;
					cin>>ty;
					if(ty) Xor=1;
					break;
				}
			}
			if(i+1<=n&&j+2<=n){
				/*
				@@@
				@@@
				*/
				if(res[i][j]==res[i+1][j+2]&&res[i+1][j]==res[i+1][j+1]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+1,j+2);cc;
					cin>>ty;
					if(!ty) Xor=1;
					break;
				}
				if((res[i][j]^1)==res[i+1][j+2]&&(res[i+1][j]^1)==res[i+1][j+1]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+1,j+2);cc;
					cin>>ty;
					if(ty) Xor=1;
					break;
				}
				if(res[i][j]==res[i+1][j+2]&&res[i][j+1]==res[i+1][j+1]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+1,j+2);cc;
					cin>>ty;
					if(!ty) Xor=1;
					break;
				}
				if((res[i][j]^1)==res[i+1][j+2]&&(res[i][j+1]^1)==res[i+1][j+1]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+1,j+2);cc;
					cin>>ty;
					if(ty) Xor=1;
					break;
				}
				if(res[i][j]==res[i+1][j+2]&&res[i][j+1]==res[i][j+2]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+1,j+2);cc;
					cin>>ty;
					if(!ty) Xor=1;
					break;
				}
				if((res[i][j]^1)==res[i+1][j+2]&&(res[i][j+1]^1)==res[i][j+2]){OK=1;
					printf("? %d %d %d %d\n",i,j,i+1,j+2);cc;
					cin>>ty;
					if(ty) Xor=1;
					break;
				}
			}
			if(j+4-1<=n){
				/*
				@@@@
				*/
				if(res[i][j]==res[i][j+3]&&res[i][j+1]==res[i][j+2]){OK=1;
					printf("? %d %d %d %d\n",i,j,i,j+3);cc;
					cin>>ty;
					if(!ty) Xor=1;
					break;
				}
				if((res[i][j]^1)==res[i][j+3]&&(res[i][j+1]^1)==res[i][j+2]){OK=1;
					printf("? %d %d %d %d\n",i,j,i,j+3);cc;
					cin>>ty;
					if(ty) Xor=1;
					break;
				}
			}
		}
	} 
	cout<<"!"<<endl;
	rb(i,1,n){
		rb(j,1,n){
			if(i%2==0&&j%2==1){
				res[i][j]^=Xor; 
			}
			else
			if(i%2==1&&j%2==0){
				res[i][j]^=Xor;
			}
			cout<<res[i][j];
		}
		cout<<endl;
	}
	return 0;
}