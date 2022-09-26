#include<bits/stdc++.h>
using namespace std;
#define N 25
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N][N];
pair<int,int> pos[N*N];
vector<vector<int> > ans;
inline void Move(const vector<int> &p){
	ans.push_back(p);
	for(auto x:p){
		assert(x);
	}
	for(int i=0;i<(int)p.size()-1;++i){
		swap(pos[p[i]],pos[p[i+1]]);
	}
	for(auto x:p){
		a[pos[x].first][pos[x].second]=x;
	}
}
void Left22(int x,int y){
	Move(vector<int>({a[x][y],a[x+1][y],a[x+1][y+1],a[x][y+1]}));
}
void Right22(int x,int y){
	Move(vector<int>({a[x][y],a[x][y+1],a[x+1][y+1],a[x+1][y]}));
}
void Left23(int x,int y){
	Move(vector<int>({a[x][y],a[x+1][y],a[x+1][y+1],a[x+1][y+2],a[x][y+2],a[x][y+1]}));
}
void Right23(int x,int y){
	Move(vector<int>({a[x][y],a[x][y+1],a[x][y+2],a[x+1][y+2],a[x+1][y+1],a[x+1][y]}));
}
void Left32(int x,int y){
	Move(vector<int>({a[x][y],a[x+1][y],a[x+2][y],a[x+2][y+1],a[x+1][y+1],a[x][y+1]}));
}
void Right32(int x,int y){
	Move(vector<int>({a[x][y],a[x][y+1],a[x+1][y+1],a[x+2][y+1],a[x+2][y],a[x+1][y]}));
}
void Swap(int x,int y,int t){   // t=0:   t=1:  
	if(!t)assert(y<m);
	if(t)assert(x<n);
	if(!t){
		if(x<n&&y+1<m){
			Right22(x,y);
			Right22(x,y+1);
			Left23(x,y);
		}
		else if(x<n&&y>1){
			Left22(x,y);
			Left22(x,y-1);
			Right23(x,y-1);
		}
		else if(x>1&&y+1<m){
			Left22(x-1,y);
			Left22(x-1,y+1);
			Right23(x-1,y);	
		}
		else{
			Right22(x-1,y);
			Right22(x-1,y-1);
			Left23(x-1,y-1);
		}
	}
	else{
		if(x+1<n&&y<m){
			Left22(x,y);
			Left22(x+1,y);
			Right32(x,y);
		}
		else if(x+1<n&&y>1){
			Right22(x,y-1);
			Right22(x+1,y-1);
			Left32(x,y-1);	
		}
		else if(x<n&&y<m){
			Right22(x,y);
			Right22(x-1,y);
			Left32(x-1,y);
		}
		else{
			Left22(x,y-1);
			Left22(x-1,y-1);
			Right32(x-1,y-1);
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
			pos[a[i][j]]=make_pair(i,j);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int x=(i-1)*m+j;
			if(i<=n-2&&j<=m-2){
				while(pos[x].second<j){
					pos[x].first==n?Left22(pos[x].first-1,pos[x].second):Right22(pos[x].first,pos[x].second);	
				}
				while(pos[x].second>j){
					pos[x].first==n?Right22(pos[x].first-1,pos[x].second-1):Left22(pos[x].first,pos[x].second-1);	
				}
				while(pos[x].first>i){
					Right22(pos[x].first-1,pos[x].second);
				}	
			}
			else{
				while(pos[x].second<j){
					Swap(pos[x].first,pos[x].second,0);
				}
				while(pos[x].second>j){
					Swap(pos[x].first,pos[x].second-1,0);
				}
				while(pos[x].first>i){
					Swap(pos[x].first-1,pos[x].second,1);
				}
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto v:ans){
		printf("%d ",(int)v.size());
		for(auto x:v){
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}