#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
char MM[505][505];
int OK[505][505];
int main(){
	ios::sync_with_stdio(false);
	memset(MM,'%',sizeof(MM));
	int n,m;
	cin>>n>>m;
	rb(i,1,n){
		rb(j,1,m) {
			cin>>MM[i][j];
		}
	}
	int res=0;
	rb(i,1,n){
		rb(j,1,m){
			if(MM[i][j]=='*'&&MM[i-1][j]=='*'&&MM[i+1][j]=='*'&&MM[i][j-1]=='*'&&MM[i][j+1]=='*'){
				res++;
				int tmpx=i,tmpy=j;
				while(tmpx<=n&&tmpx>0&&tmpy<=m&&tmpy>0){
					if(MM[tmpx][tmpy]!='*') break;
					OK[tmpx][tmpy]=1;
					tmpx++;
				}
				tmpx=i,tmpy=j;
				while(tmpx<=n&&tmpx>0&&tmpy<=m&&tmpy>0){
					if(MM[tmpx][tmpy]!='*') break;
					OK[tmpx][tmpy]=1;
					tmpx--;
					
				}tmpx=i,tmpy=j;
				while(tmpx<=n&&tmpx>0&&tmpy<=m&&tmpy>0){
					if(MM[tmpx][tmpy]!='*') break;
					OK[tmpx][tmpy]=1;
					tmpy++;
				}tmpx=i,tmpy=j;
				while(tmpx<=n&&tmpx>0&&tmpy<=m&&tmpy>0){
					if(MM[tmpx][tmpy]!='*') break;
					OK[tmpx][tmpy]=1;
					tmpy--;
				}
				tmpx=i,tmpy=j;
			}
//			if(OK[i][j]==0)
//			if(MM[i][j]=='*'&&(MM[i-1][j]!='*'||MM[i+1][j]!='*'||MM[i][j-1]!='*'||MM[i][j+1]!='*')){
//				cout<<i<<" "<<j<<endl;
//				cout<<"NO";
//				return 0;
//			}
		}
	}
	rb(i,1,n){
		rb(j,1,m){
			if(MM[i][j]=='*'&&OK[i][j]==0){
				cout<<"NO";
				return 0;
			}
		}
	}
	if(res!=1){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}
	return 0;
}