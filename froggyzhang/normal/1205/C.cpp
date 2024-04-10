#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
#define y2 ysgh
int n,a[N][N];
inline int Ask(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	int x;
	cin>>x;
	return x^1;
}
void Report(){
	cout<<"! "<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	a[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if((i==1&&j==1)||(i==n&&j==n)||(i==2&&j==1))continue;
			if(i>1&&j>1)a[i][j]=Ask(i-1,j-1,i,j)^a[i-1][j-1];
			else if(i>2)a[i][j]=Ask(i-2,j,i,j)^a[i-2][j];
			else if(j>2)a[i][j]=Ask(i,j-2,i,j)^a[i][j-2];
		}
		if(i==2)a[2][1]=Ask(2,1,2,3)^a[2][3];
	}
	for(int i=1;i<=n-2;++i){
		if(a[i][i]^a[i+2][i+2]){
			int t;
			if((a[i][i]^a[i+1][i]^a[i+1][i+1]^a[i+2][i+1])==0){
				t=Ask(i,i,i+2,i+1)^a[i+2][i+1]^a[i][i]; 
			}
			else{
				t=Ask(i+1,i,i+2,i+2)^a[i+1][i]^a[i+2][i+2];
			}
			if(t){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=n;++j){
						if((i+j)&1)a[i][j]^=1;
					}
				}	
			}
			Report();
		}
	}
	return 0;
}